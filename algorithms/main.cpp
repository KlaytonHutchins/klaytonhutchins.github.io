#include <iostream>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include "Case.h"
#include "Node.h"
#include "DoublyLL.h"

using namespace std;

time_t current_time = time(NULL);
int theYear = 1970 + (current_time / 31537970);

string toLower(string str);
string sanitizeFileName(string str);
size_t WriteToFile(void* ptr, size_t size, size_t nmemb, FILE* stream);
void downloadPDFs(DoublyLL<Case>* caseList, string theYear);
bool downloadPDF(Node<Case>* curr, string& savePath);
size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
void scrape(string url, string fileName);
bool downloadMp3(string url, string outputFilename);
void downloadMp3s(DoublyLL<Case>* caseList, string theYear);
string extractDataFromTdLine(string str);
string extractHrefFromLinkLine(string str);
string extractCaseNameFromLinkLine(string str);
string convertDate(string str);
DoublyLL<Case>* generateListFromHtml(string inFilename);
void writeReadmeFromList(DoublyLL<Node<Case>>* casesForTermYear, string termYear);

string toLower(string str) {
        for (size_t i = 0; i < str.length(); i++) {
                str[i] = tolower(str[i]);
        }
        return str;
}

string sanitizeFileName(string str) {
        string result = "";
        for (size_t i = 0; i < str.length(); i++) {
                if (str[i] != '.' && str[i] != ',' && str[i] != ' ') {
                        result = result + str[i];
                } 
        }
        return result;
}

size_t WriteToFile(void* ptr, size_t size, size_t nmemb, FILE* stream) {
        return fwrite(ptr, size, nmemb, stream);
}

void downloadPDFs(DoublyLL<Case>* caseList, string theYear) {
        string saveFolder = "../scotus/" + theYear + "/resources/";
        system(("mkdir -p " + saveFolder).c_str());
        Node<Case>* curr = caseList->getHead();
        while (curr) {
                string fileName = saveFolder + sanitizeFileName(curr->getData()->getDocketNum()) + ".pdf";
                cout << "Downloading: " << curr->getData()->getDocketNum() << " -> " << fileName << endl;
                if (downloadPDF(curr, fileName)) {
                        //cout << "Saved: " << fileName << endl;
                } else {
                        cerr << "Download failed: " << curr->getData()->getDocketNum() << endl;
                }
                curr = curr->getNext();
        }
}

bool downloadPDF(Node<Case>* curr, string& savePath) {
        CURL* curl = curl_easy_init();
        if (!curl) {
                cerr << "Failed to initialize curl" << endl;
                return false;
        }
        FILE* file = fopen(savePath.c_str(), "wb");
        if (!file) {
                cerr << "Failed to open file: " << savePath << endl;
                curl_easy_cleanup(curl);
                return false;
        }
        curl_easy_setopt(curl, CURLOPT_URL, curr->getData()->getUrl().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteToFile);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
                cerr << "Failed to download: " << curr->getData()->getUrl() << " | Error: " << curl_easy_strerror(res) << endl;
                fclose(file);
                remove(savePath.c_str()); // Remove incomplete file
                curl_easy_cleanup(curl);
                return false;
        }
        fclose(file);
        curl_easy_cleanup(curl);
        return true;
}

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ofstream* outFile = static_cast<ofstream*>(userp);
        outFile->write(static_cast<char*>(contents), size * nmemb);
        return size * nmemb;
}

void scrape(string url, string outputFilename) {
        CURL* curl;
        CURLcode res;
        ofstream outFile(outputFilename);

        if (!outFile.is_open()) {
                cerr << "Error opening output file!" << endl;
        }

        curl = curl_easy_init();
        if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outFile);

                res = curl_easy_perform(curl);

                if (res != CURLE_OK) {
                        cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
                } else {
                        //cout << "Data successfully fetched and saved to " << outputFilename << endl;
                }

                curl_easy_cleanup(curl);
        } else {
                cerr << "Failed to initialize curl." << endl;
        }

        outFile.close();
}

bool downloadMp3(string url, string outputFilename) {
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		ofstream outFile(outputFilename, ios::binary);
		if (!outFile) {
			cerr << "Error opening file: " << outputFilename << endl;
			return false;
		}
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
	        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outFile);
	        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects

	        res = curl_easy_perform(curl);
	        if (res != CURLE_OK) {
	        	cerr << "Download failed: " << curl_easy_strerror(res) << endl;
			return false;
	        } else {
	        	//cout << "Download successful: " << outputFilename << endl;
	        }

	        curl_easy_cleanup(curl);
	        outFile.close();
	} else {
	        cerr << "Failed to initialize curl" << endl;
		return false;
	}
	return true;
}

void downloadMp3s(DoublyLL<Case>* caseList, string theYear) {
        string saveFolder = "../scotus/" + theYear + "/resources/";
        system(("mkdir -p " + saveFolder).c_str());
        Node<Case>* curr = caseList->getHead();
        while (curr) {
                string fileName = saveFolder + sanitizeFileName(curr->getData()->getDocketNum()) + ".mp3";
                cout << "Downloading: " << curr->getData()->getDocketNum() << " -> " << fileName << endl;
		// https://www.supremecourt.gov/media/audio/mp3files/23-7809.mp3
		string url = "https://www.supremecourt.gov/media/audio/mp3files/" + curr->getData()->getDocketNum() + ".mp3";
                // string url = "https://api.oyez.org/case_media/oral_argument_audio/" + "25480" + "/download";
		if (downloadMp3(url, fileName)) {
                        //cout << "Saved: " << fileName << endl;
                } else {
                        cerr << "Download failed: " << curr->getData()->getDocketNum() << endl;
                }
                curr = curr->getNext();
        }
}

string extractDataFromTdLine(string str) {
	int startIdx, endIdx;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '>' && (i < str.length() - 3)) {
			startIdx = i;
		}
		if (str[i] == '<' && i > 1) {
			endIdx = i;
		}
	}
	return str.substr(startIdx + 1, (endIdx - startIdx - 1));
}

string extractHrefFromLinkLine(string str) {
	int idx = str.find('\'');
	str = str.substr(idx + 1);
	idx = str.find('\'');
	return "https://www.supremecourt.gov" + str.substr(0, idx);
}

string extractCaseNameFromLinkLine(string str) {
	int bracketCount = 0;
	int startIdx;
	for (int i = str.length() - 1; i > 0; i--) {
		if (str[i] == '>') {
			bracketCount++;
		}
		if (bracketCount == 3) {
			startIdx = i;
			str = str.substr(startIdx + 1);
        		return str.substr(0, str.find('<'));
		}
	}
	return "";
}

string convertDate(string str) {
	string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	int firstSlash = -1;
	int secondSlash = -1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '/') {
			if (firstSlash == -1) {
				firstSlash = i;
			} else {
				secondSlash = i;
			}
		}
	}
	int dayOfMonth;
	string monthStr;
	try {
		dayOfMonth = stoi(str.substr((firstSlash + 1), (secondSlash - firstSlash)));
		monthStr = months[stoi(str.substr(0, firstSlash)) - 1];
	} catch (invalid_argument& err) {
		cout << "invalid arg: " << err.what() << endl;
	}
	string yearStr = str.substr((secondSlash + 1), (str.length() - secondSlash - 1));
	return (to_string(dayOfMonth) + " " + monthStr + " " + yearStr);
}

DoublyLL<Case>* generateListFromHtml(string inFilename) {
	// reopen temp html file
	ifstream inFile(inFilename);
	string str;
	// scan through line-by-line
	DoublyLL<Case>* cases = new DoublyLL<Case>();
	bool foundTable = false;
	while (getline(inFile, str, '\n')) {
		int lastSpace = str.rfind(' ');
		if (str.substr((lastSpace + 1), 13) == "scope=\"col\">R") {
			foundTable = true;
		}
		if (foundTable && str.substr((lastSpace + 1), 4) == "<tr>") {
			string tempStr;
			Case* newCase = new Case();

			getline(inFile, str, '\n');
			tempStr = extractDataFromTdLine(str);
			if (tempStr == "R-") {
				continue;
			}
			newCase->setOrdNum(tempStr);

			getline(inFile, str, '\n');
			tempStr = extractDataFromTdLine(str);
			string date = convertDate(tempStr);
			newCase->setDate(date);

			getline(inFile, str, '\n');
			tempStr = extractDataFromTdLine(str);
			newCase->setDocketNum(tempStr);

			getline(inFile, str, '\n');
			// url = first part
			// caseName = second part;
			newCase->setUrl(extractHrefFromLinkLine(str));
			newCase->setCaseName(extractCaseNameFromLinkLine(str));

			getline(inFile, str, '\n');
			// trash
			getline(inFile, str, '\n');
			// trash
			cases->insertFront(new Node<Case>(newCase));
		}
	}
	inFile.close();
	return cases;
}

void writeReadmeFromList(DoublyLL<Case>* casesForTermYear, string termYear) {
	string outFileName = "../scotus/" + termYear + "/README.md";
	ofstream outFile(outFileName);
	outFile << "---" << endl << "layout: default" << endl << "title: SCOTUS Term Year ";
	outFile << termYear << endl << "---" << endl << endl << "### Cases" << endl;
	Node<Case>* curr = casesForTermYear->getHead();
	while (curr) {
		outFile << "*  [" << curr->getData()->getCaseName() << "](" << sanitizeFileName(curr->getData()->getDocketNum()) << ".md)" << endl;
		curr = curr->getNext();
	}
	outFile.close();
}

void writeCasePages(DoublyLL<Case>* casesForTermYear, string termYear) {
	Node<Case>* curr = casesForTermYear->getHead();
        while (curr) {
		string outFileName = "../scotus/" + termYear + "/" + sanitizeFileName(curr->getData()->getDocketNum()) + ".md";
        	ofstream outFile(outFileName);
		curr->getData()->buildCasePage(outFile, termYear) ;
                curr = curr->getNext();
		outFile.close();
        }
}

int main() {
	for (int i = 2016; i < (theYear + 1); i++) {
		cout << "Year: " << to_string(i) << endl;
		// download pdfs, get html, create linked list, write year file, write case file
		string url = "https://www.supremecourt.gov/opinions/slipopinion/" + to_string(i - 2000);;
		string tempStorageFilename = "tempHtml.txt";
        	scrape(url, tempStorageFilename);
		cout << "        Scraped" << endl;
		DoublyLL<Case>* cases = new DoublyLL<Case>();
		cases = generateListFromHtml(tempStorageFilename);
		cout << "        List made" << endl;
		writeReadmeFromList(cases, to_string(i));
		cout << "        README done" << endl;
		writeCasePages(cases, to_string(i));
		cout << "        Case pages done" << endl;
		//downloadPDFs(cases, to_string(i));
		//cout << "        PDFs" << endl;
		//downloadMp3s(cases, to_string(i));
		//cout << "        MP3s" << endl;
	}
	remove("tempHtml.txt");
}

