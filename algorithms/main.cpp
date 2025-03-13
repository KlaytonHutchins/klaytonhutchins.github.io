#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include "DoublyLL.cpp"

using namespace std;

/*******************************************
           Global Variables Here
*****************************************8*/
int yearToAccess = 2023;
string inFileName = to_string(yearToAccess) + "input.txt";
string outFileName = "output.txt";
string oyezUrl = "https://www.oyez.org/cases/";
// full = https://www.oyez.org/cases/2024/23-167
// oyezUrl + "2024/23-167";
string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
/*******************************************
           Global Variables Here
*****************************************8*/

//class Node;
//class DoublyLL;

string toLower(string str);
string sanitizeFileName(string str);
size_t WriteToFile(void* ptr, size_t size, size_t nmemb, FILE* stream);
void downloadPDFs(DoublyLL<CaseNode>* caseList);
bool downloadPDF(CaseNode* curr, string& savePath);

//Node class with previous and next nodes.
//Member variables are private, must use getter and setter functions.
/*class Node {
public:
        //Construct new node with a name
        Node(string ordNum, string date, string docketNum, string caseName, string url) {
                ordinalNumber = ordNum;
                dateFiled = date;
                docketNumber = docketNum;
                fullCaseName = caseName;
                scotusUrl = url;
                next = nullptr;
                prev = nullptr;
        }
        ofstream& buildCasePage(ofstream& outFile) {
                string myDateFormat = to_string(stoi(dateFiled.substr(3, 2))) + " " + months[stoi(dateFiled.substr(0, 2))] + " " + dateFiled.substr(6, 4);
                outFile << "---" << endl << "layout: scotus_case" << endl << "title: " << fullCaseName << endl << "---" << endl << endl;
                outFile << "| Docket # | Date Decided | SCOTUS Opinion | Oyez |" << endl;
                outFile << "| " << docketNumber << " | " << myDateFormat << " | [Link](" << scotusUrl << ") | ";
                outFile << "[Link](" << oyezUrl << yearToAccess << "/" << docketNumber << ") |" << endl << endl;
                outFile << "<audio controls>" << endl << "   <source src='./resources/" << docketNumber << ".mp3' type='audio/mpeg'>" << endl << "</audio>";
                outFile << endl << endl << "<object data='./resources/" << docketNumber << ".pdf' type='application/pdf'></object>" << endl << endl;
                outFile << "---" << endl << endl << "[Up](./README.md)";
                return outFile;
        }
        //Getters and Setters
        void setOrdNum(string n) {
                ordinalNumber = n;
        }
        string getOrdNum() {
                return ordinalNumber;
        }
        void setDate(string n) {
                dateFiled = n;
        }
        string getDate() {
                return dateFiled;
        }
        void setDocketNum(string n) {
                docketNumber = n;
        }
        string getDocketNum() {
                return docketNumber;
        }
        void setCaseName(string n) {
                fullCaseName = n;
        }
        string getCaseName() {
                return fullCaseName;
        }
        void setUrl(string n) {
                scotusUrl = n;
        }
        string getUrl() {
                return scotusUrl;
        }
        void setNext(Node* n) {
                next = n;
        }
        Node* getNext() {
                return next;
        }
        void setPrev(Node* p) {
                prev = p;
        }
        Node* getPrev() {     
                return prev;
        }
private:
        string ordinalNumber;
        string dateFiled;
        string docketNumber;
        string fullCaseName;
        string scotusUrl;
        Node* next;
        Node* prev;
};*/

//Doubly Linked List class with private head and tail.
//Contains:
//Constructor, Destructor, Getters and Setters.
//Self Sorting Insert function, Delete function, and Traversal functions.
/*class DoublyLL {
public:
        //Construct new empty Doubly Linked List
        DoublyLL() {
                head = nullptr;
                tail = nullptr;
        }
        //Destructor
        ~DoublyLL() {
                Node* curr = head;
                while (curr) {
                        Node* tempNext = curr->getNext();
                        delete curr;
                        curr = tempNext;
                }
        }
        //Insert function

        void insert(string nameToInsert) {
                Node* newNode = new Node(nameToInsert);
                if (!head) {  //empty list
                        head = newNode;
                        tail = newNode;
                } else if (nameToInsert < head->getName()) {  //insert at head
                        newNode->setNext(head);
                        head->setPrev(newNode);
                        head = newNode;
                } else if (nameToInsert > tail->getName()) {  //insert at tail
                        newNode->setPrev(tail);
                        tail->setNext(newNode);
                        tail = newNode;
                } else {  //insert somewhere in the middle of the list
                        Node* curr = head;
                        while(curr) {  //loop through list to find insertion point
                                if (nameToInsert < curr->getName()) {  //insert before curr
                                        newNode->setNext(curr);
                                        newNode->setPrev(curr->getPrev());
                                        curr->getPrev()->setNext(newNode);
                                        curr->setPrev(newNode);
                                        break;
                                }
                                curr = curr->getNext();
                        }
                }
        }

        void insertBack(string ordNum, string date, string docketNum, string caseName, string url) {
                Node* newNode = new Node(ordNum, date, docketNum, caseName, url);
                if (!head) {  //empty list
                        head = newNode;
                        tail = newNode;
                } else {
                        newNode->setPrev(tail);
                        tail->setNext(newNode);
                        tail = newNode;
                }
        }
        //Delete function

        void deleteNode(string nameToDelete) {
                Node* curr = head;
                while (curr) {
                        Node* nextNode = curr->getNext();
                        if (curr->getName() == nameToDelete) {
                                if (curr->getPrev()) {  //if curr != head
                                        curr->getPrev()->setNext(curr->getNext());
                                } else {  //curr == head, reassign head to the second node
                                        head = curr->getNext();
                                }
                                if (curr->getNext()) {  //if curr != tail
                                        curr->getNext()->setPrev(curr->getPrev());
                                } else {  //deleting tail, reassign tail to its previous node
                                        tail = curr->getPrev();
                                }
                                delete curr;
                                break;  //comment out if expecting duplicates and want to delete all instances
                        }
                        curr = nextNode;
                }
        }

        //Traverse function, uses ofstream to pass data back to main

        ofstream& traverseAscending(ofstream& outFile) {
                Node* curr = head;
                while (curr) {
                        outFile << curr->getName() << endl;
                        curr = curr->getNext();
                }
                return outFile;
        }

        //Traverse function, uses ofstream to pass data back to main

        ofstream& traverseDescending(ofstream& outFile) {
                Node* curr = tail;
                while (curr) {
                        outFile << curr->getName() << endl;
                        curr = curr->getPrev();
                }
                return outFile;
        }

        ofstream& buildYearReadMe(ofstream& outFile) {
                Node* curr = tail;
                outFile << "---" << endl << "layout: default" << endl << "title: SCOTUS Term Year " << yearToAccess;
                outFile << endl << "---" << endl << endl << "### Cases" << endl;
                while (curr) {
                        outFile << "*  [" << curr->getCaseName() << "](" << sanitizeFileName(curr->getDocketNum()) << ".md)" << endl;
                        curr = curr->getPrev();
                }
                outFile << endl << "---" << endl << endl << "[Prev](../" << (yearToAccess - 1);
                outFile << "/README.md) | [Up](../README.md) | [Next](../" << (yearToAccess + 1) << "/README.md)" << endl;
                return outFile;
        }
        //Getters and Setters   
        void setHead(Node* h) {
                head = h;
        }
        Node* getHead() {
                return head;
        }
        void setTail(Node* t) {
                tail = t;
        }
        Node* getTail() {
                return tail;
        }
private:
        Node* head;
        Node* tail;
};*/
//Helper function to convert text to all lower case
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
        string saveFolder = "../scotus/" + to_string(yearToAccess) + "/resources/";
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
        DoublyLL<CaseNode> myList = DoublyLL<CaseNode>();
        myList.insertBack(new CaseNode("32", "03/23/2023", "24-975", "Klayton v. Selena", "www.website.com"));
        myList.insertBack(new CaseNode("33", "03/24/2023", "24-976", "Klayton v. Quiche", "www.websites.com"));
        myList.insertBack(new CaseNode("34", "03/25/2023", "24-977", "Klayton v. Jack", "www.web.com"));
        myList.insertBack(new CaseNode("35", "03/26/2023", "24-978", "Jack v. Quiche", "www.site.com"));
        cout << myList.getHead()->getNext()->getDocketNum() << endl;

/*
        ifstream inFile;
        inFile.open(inFileName);
        string ordNum, date, docketNum, caseName, url;
        DoublyLL* entryList = new DoublyLL;
        while (getline(inFile, ordNum, '\t')) {
                getline(inFile, date, '\t');
                getline(inFile, docketNum, '\t');
                getline(inFile, caseName, '\t');
                getline(inFile, url, '\n');
                cout << "Reading " << docketNum << endl;
                entryList->insertBack(ordNum, date, docketNum, caseName, url);
        }
        inFile.close();
        ofstream outFile;
        outFile.open("../scotus/" + to_string(yearToAccess) + "/README.md");
        cout << "Building " << to_string(yearToAccess) << " README" << endl;
        entryList->buildYearReadMe(outFile);
        outFile.close();

        Node* curr = entryList->getHead();
        string pageName;
        while (curr) {
                pageName = "../scotus/" + to_string(yearToAccess) + "/" + sanitizeFileName(curr->getDocketNum()) + ".md";
                outFile.open(pageName);
                curr->buildCasePage(outFile);
                outFile.close();
                curr = curr->getNext();
        }
        downloadPDFs(entryList);
        delete entryList;
        return 0;
*/
}
