#include <iostream>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include "Case.h"
#include "Node.h"
#include "DoublyLL.cpp"

using namespace std;

// int currYear = idk, system . get year ?
int theYear = 2023;

string toLower(string str);
string sanitizeFileName(string str);
size_t WriteToFile(void* ptr, size_t size, size_t nmemb, FILE* stream);
void downloadPDFs(DoublyLL<Node<Case>>* caseList);
bool downloadPDF(Node<Case>* curr, string& savePath);
size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
void scrape(string url, string fileName);
DoublyLL<Node<Case>>* generateListFromHtml(string termYear);
void writeFileFromList(DoublyLL<Node<Case>>* casesForTermYear);

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
/*
void downloadPDFs(DoublyLL<Node<Case>>* caseList) {
        string saveFolder = "../scotus/" + to_string(theYear) + "/resources/";
        system(("mkdir -p " + saveFolder).c_str());
        Node<Case>* curr = caseList->getHead();
        while (curr) {
                string fileName = saveFolder + sanitizeFileName(curr->getData()->getDocketNum()) + ".pdf";
                cout << "Downloading: " << curr->getData()->getUrl() << " -> " << fileName << endl;
                if (downloadPDF(curr, fileName)) {
                        cout << "Saved: " << fileName << endl;
                } else {
                        cerr << "Download failed: " << curr->getData()->getUrl() << endl;
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
}*/

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
                        cout << "Data successfully fetched and saved to " << outputFilename << endl;
                }

                curl_easy_cleanup(curl);
        } else {
                cerr << "Failed to initialize curl." << endl;
        }

        outFile.close();
}

DoublyLL<Node<Case>>* generateListFromHtml(string termYear) {
	// reopen temp html file
	ifstream inFile("tempHtml.txt");
	string str;
	// scan through line-by-line
	DoublyLL<Node<Case>>* cases = new DoublyLL<Node<Case>>();
	while (getline(inFile, str, '\n')) {
		if (str == "<tr>") {
			//Node<Case>* newNode = new Node<Case>();
			getline(inFile, str, '\n');
			// newNode->setOrdNum(str);
			getline(inFile, str, '\n');
			// date = convertDate(str);
			getline(inFile, str, '\n');
			// caseNum = str;
			getline(inFile, str, '\n');
			// url = first part
			// caseName = second part;
			getline(inFile, str, '\n');
			// trash
			getline(inFile, str, '\n');
			// trash
			// myList->insert ( , back, front)?
		}
		/* EXAMPLE of 1 case
<tr>
	<td style="text-align: center;">17</td>
	<td style="text-align: center;">3/05/25</td>
	<td style="text-align: center; white-space: nowrap;">23-713</td>
	<td><a href="/opinions/24pdf/23-713_jifl.pdf" target="_blank" title="The Department of Veterans Affairs’ determination that the evidence regarding a service-related disability claim is in “approximate balance” pursuant to the “benefit-of-the-doubt rule,” 38 U. S. C. §5107(b), is a predominantly factual determination reviewed only for clear error.">Bufkin v. Collins</a></td>
	<td style="text-align: center;">T</td>
	<td style="text-align: center;"><span style="white-space:nowrap;">604/1</span></td>
</tr>
*/
	}
	//return new DoublyLL<CaseNode>();
	return cases;
	// if contains <li> write, otherwise skip
}

void writeFileFromList(DoublyLL<Node<Case>>* casesForTermYear) {
	
}

int main() {
	string url = "https://www.supremecourt.gov/opinions/slipopinion/" + to_string(theYear - 2000);
        string outputFilename = "tempHtml.txt";
	scrape(url, outputFilename);
}

