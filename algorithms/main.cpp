#include <iostream>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include "Nodes.h"
#include "DoublyLL.cpp"

using namespace std;

int theYear = 2023;

string toLower(string str);
string sanitizeFileName(string str);
size_t WriteToFile(void* ptr, size_t size, size_t nmemb, FILE* stream);
void downloadPDFs(DoublyLL<CaseNode>* caseList);
bool downloadPDF(CaseNode* curr, string& savePath);

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

void downloadPDFs(DoublyLL<CaseNode>* caseList) {
        string saveFolder = "../scotus/" + to_string(theYear) + "/resources/";
        system(("mkdir -p " + saveFolder).c_str());
        CaseNode* curr = caseList->getHead();
        while (curr) {
                string fileName = saveFolder + sanitizeFileName(curr->getDocketNum()) + ".pdf";
                cout << "Downloading: " << curr->getUrl() << " -> " << fileName << endl;
                if (downloadPDF(curr, fileName)) {
                        cout << "Saved: " << fileName << endl;
                } else {
                        cerr << "Download failed: " << curr->getUrl() << endl;
                }
                curr = curr->getNext();
        }
}

bool downloadPDF(CaseNode* curr, string& savePath) {
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
        curl_easy_setopt(curl, CURLOPT_URL, curr->getUrl().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteToFile);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
                cerr << "Failed to download: " << curr->getUrl() << " | Error: " << curl_easy_strerror(res) << endl;
                fclose(file);
                remove(savePath.c_str()); // Remove incomplete file
                curl_easy_cleanup(curl);
                return false;
        }
        fclose(file);
        curl_easy_cleanup(curl);
        return true;
}

int main() {
//        DoublyLL<CaseNode> myList = DoublyLL<CaseNode>();
//        myList.insertBack(new CaseNode("32", "03/23/2023", "24-975", "Klayton v. Selena", "www.website.com"));
//        myList.insertBack(new CaseNode("33", "03/24/2023", "24-976", "Klayton v. Quiche", "www.websites.com"));
//        myList.insertBack(new CaseNode("34", "03/25/2023", "24-977", "Klayton v. Jack", "www.web.com"));
//        myList.insertBack(new CaseNode("35", "03/26/2023", "24-978", "Jack v. Quiche", "www.site.com"));
//        cout << myList.getHead()->getNext()->getDocketNum() << endl;


        ifstream inFile;
//        inFile.open(inFileName);
        inFile.open("2023input.txt");
//        string ordNum, date, docketNum, caseName, url;
        DoublyLL<CaseNode>* entryList = new DoublyLL<CaseNode>();
        string str;
        while (getline(inFile, str, '\n')) {
                  //CaseNode::CaseNode(sstream& inputStr)
                  stringstream sstr(str);
                  entryList->insertBack(new CaseNode(sstr));
//                getline(inFile, date, '\t');
//                getline(inFile, docketNum, '\t');
//                getline(inFile, caseName, '\t');
//                getline(inFile, url, '\n');
//                cout << "Reading " << docketNum << endl;
//                entryList->insertBack(ordNum, date, docketNum, caseName, url);
        }
        
        inFile.close();/*
        ofstream outFile;
        outFile.open("../scotus/" + to_string(yearToAccess) + "/README.md");
        cout << "Building " << to_string(yearToAccess) << " README" << endl;
        entryList->buildYearReadMe(outFile);
        outFile.close();*/

        CaseNode* curr = entryList->getHead();
        //string pageName;
//        cout << curr->getOrdNum() << " " << curr->getDate();
//        cout << " " << curr->getDocketNum() << " " << curr->getCaseName();
//        cout << " " << curr->getUrl() << endl;
        cout << "size: " << entryList->getSize() << endl;
        int count = 2;
        while (curr && count > 0) {
                cout << curr->getOrdNum() << endl;
                cout << curr->getDate() << endl;
                cout << curr->getDocketNum() << endl;
                cout << curr->getCaseName() << endl;
                cout << curr->getUrl() << endl;
//                pageName = "../scotus/" + to_string(yearToAccess) + "/" + sanitizeFileName(curr->getDocketNum()) + ".md";
//                outFile.open(pageName);
//                curr->buildCasePage(outFile);
//                outFile.close();
                curr = curr->getNext();
                count--;
        }
//        downloadPDFs(entryList);
        delete entryList;
        return 0;

}
