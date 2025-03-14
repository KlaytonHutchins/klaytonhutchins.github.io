#include <iostream>
#include <fstream>
#include <vector>
#include <curl/curl.h>

using namespace std;

string wikiFrontUrl = "https://en.wikipedia.org";

string inFileName = "kryptosIn.txt";
string outFileName = "kryptosOut.txt";

vector<char> k4letters({'O', 'B', 'K', 'R', 'U', 'O', 'X', 'O', 'G', 'H', 'U', 'L', 'B', 'S', 'O', 'L', 'I', 'F', 'B', 'B', 'W', 'F', 'L', 'R', 'V', 'Q', 'Q', 'P', 'R', 'N', 'G', 'K', 'S', 'S', 'O', 'T', 'W', 'T', 'Q', 'S', 'J', 'Q', 'S', 'S', 'E', 'K', 'Z', 'Z', 'W', 'A', 'T', 'J', 'K', 'L', 'U', 'D', 'I', 'A', 'W', 'I', 'N', 'F', 'B', 'N', 'Y', 'P', 'V', 'T', 'T', 'M', 'Z', 'F', 'P', 'K', 'W', 'G', 'D', 'K', 'Z', 'X', 'T', 'J', 'C', 'D', 'I', 'G', 'K', 'U', 'H', 'U', 'A', 'U', 'E', 'K', 'C', 'A', 'R'});
vector<int> k4numbers({14, 1, 10, 17, 20, 14, 23, 14, 6, 7, 20, 11, 1, 18, 14, 11, 8, 5, 1, 1, 22, 5, 11, 17, 21, 16, 16, 15, 17, 13, 6, 10, 18, 18, 14, 19, 22, 19, 16, 18, 9, 16, 18, 18, 4, 10, 25, 25, 22, 0, 19, 9, 10, 11, 20, 3, 8, 0, 22, 8, 13, 5, 1, 13, 24, 15, 21, 19, 19, 12, 25, 5, 15, 10, 22, 6, 3, 10, 25, 23, 19, 9, 2, 3, 8, 6, 10, 20, 7, 20, 0, 20, 4, 10, 2, 0, 17});

vector<int> convertToNumbers(vector<char> letterVect) {
	vector<int> resultVect;
	int thisVal;
	for (int i = 0; i < letterVect.size(); i++) {
		thisVal = letterVect[i] - 65;
		resultVect.push_back(thisVal);
	}
	return resultVect;
}
vector<char> convertToLetters(vector<int> numberVect) {
        vector<char> resultVect;  
        char thisVal;
        for (int i = 0; i < numberVect.size(); i++) {
                thisVal = 'A' + numberVect[i];
                resultVect.push_back(thisVal);
        }
        return resultVect;
}

//int matr[2][2] = {{14,1},{10,17}};
//int matr[2][2] = {{19,5},{24,8}};

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	ofstream* outFile = static_cast<ofstream*>(userp);
	outFile->write(static_cast<char*>(contents), size * nmemb);
	return size * nmemb;
}

void convertToNumsHelper() {
	cout << "k4numbers vector:" << endl;
	for (int i = 0; i < k4numbers.size(); i++) {
		cout << k4numbers[i] << " ";
	}
	cout << endl << "k4letters converted:" << endl;
	vector<int> outVect = convertToNumbers(k4letters);
	for (int i = 0; i < outVect.size(); i++) {
                cout << outVect[i] << " ";
        }
	cout << endl;
}

void matrixMult() {
	int matr[2][2] = {{14,1},{10,17}};
	//int matr[2][2] = {{19,5},{24,8}};
	ifstream inFile;
	inFile.open(inFileName);
	
	ofstream outFile;
	outFile.open(outFileName);
	
	int num1, num2;
	int out1, out2;
	char ch1, ch2;
	while (inFile >> num1) {
		inFile >> num2;
		out1 = ((matr[0][0] * num1) + (matr[0][1] * num2)) % 26;
		out2 = ((matr[1][0] * num1) + (matr[1][1] * num2)) % 26;
		ch1 = 'A' + out1;
		ch2 = 'A' + out2;
		outFile << ch1 << " " << ch2 << " ";
		
		
	}
	
	inFile.close();
	outFile.close();
}

int scrape() {
	const string url = "https://en.wikipedia.org/wiki/Category:Classical_ciphers";
	const string outputFilename = "ciphers.txt";

	CURL* curl;
	CURLcode res;
	ofstream outFile(outputFilename);

	if (!outFile.is_open()) {
		cerr << "Error opening output file!" << endl;
		return 1;
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
		return 1;
	}

	outFile.close();
	return 0;
}

string sanitizeFileName(string str) {
        string result = "";
        char ch;
	for (size_t i = 0; i < str.length(); i++) {
		ch = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
		if (ch == ' ' || ch == ',' || ch == '.' || ch == '-') {
			ch = '_';
		}
		result += ch;
        }
        return result;	
}

void writeCiphersPage() {
	string headerLinks = "### [Home](../README.md) - [K0](./K0.md) - [K1](./K1.md) - [K2](./K2.md) - [K3](./K3.md) - [K4](./K4.md) - [K5](./K5.md) - Ciphers";
	ifstream inFile;
	ofstream outFile;
	ofstream newFile;
	inFile.open(inFileName);
	outFile.open("../kryptosSubParts/ciphers.md");
	string hrefStr, titleStr, filenameStr;
        outFile << "---" << endl << "layout: default" << endl << "title: Ciphers" << endl;
        outFile << "---" << endl << endl << headerLinks << endl << endl << "---" << endl << endl;
	outFile << "| Cipher Name | My Notes | Wiki Link |" << endl;
	outFile << "|-------------|----------|-----------|" << endl;
	while (getline(inFile, hrefStr, ' ')) {
		getline(inFile, titleStr, '\n');
		hrefStr = wikiFrontUrl + hrefStr.substr(6, hrefStr.length() - 7);
		titleStr = titleStr.substr(7, titleStr.length() - 8);
		filenameStr = "./" + sanitizeFileName(titleStr) + ".md";
		outFile << "| " << titleStr << " | [Notes](" << filenameStr << ") | [Wiki](" << hrefStr << ") |" << endl;
		//outFile << "*  <button name=\"button\" onclick=\"" << filenameStr << "\" href=\"" << filenameStr << "\">My Notes</button>";
		//outFile << "  <button name=\"button\" onclick=\"" << hrefStr << "\" href=\"" << hrefStr << "\">Wikipedia</button>";
		//outFile << "  " << titleStr << endl;
		//outFile << "*  [" << titleStr << "](" << hrefStr << ")" << endl;
		newFile.open("../kryptosSubParts/" + sanitizeFileName(titleStr) + ".md");
		newFile << "---" << endl << "layout: default" << endl << "title: " << titleStr << endl << "---" << endl;
		newFile.close();
	}
	outFile << endl << "---" << endl << endl << "[Up](../README.md)" <<endl;
	inFile.close();
	outFile.close();
}

int main() {
	writeCiphersPage();
	//string test = "Aj,sdf-nk. aGF";
	//cout << test << endl;
	//cout << sanitizeFileName(test) << endl;
}

