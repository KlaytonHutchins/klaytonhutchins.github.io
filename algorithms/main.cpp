#include <iostream>
#include <fstream>

using namespace std;

//Change file names here if applicable
string inFileName = "input.txt";
string outFileName = "output.txt";
string oyezUrl = "https://www.oyez.org/cases/";
// full = https://www.oyez.org/cases/2024/23-167
// oyezUrl + "2024/23-167";
string months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

//Node class with previous and next nodes.
//Member variables are private, must use getter and setter functions.
class Node {
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
                outFile << "---\nlayout: scotus_case\ntitle: Hamm v. Smith\n---\n\nDocket: " << docketNumber << endl << endl;
                outFile << "Date: " << stoi(dateFiled.substr(3, 2)) << " " << months[stoi(dateFiled.substr(0, 2))] << " " << dateFiled.substr(6, 4) << endl << endl;
                outFile << "[SCOTUS Link](" << scotusUrl << ")" << endl << endl;
                outFile << "[Oyez Link](" << oyezUrl << dateFiled.substr(6, 4) << "/" << docketNumber << ")" << endl << endl;
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
};

//Doubly Linked List class with private head and tail.
//Contains:
//Constructor, Destructor, Getters and Setters.
//Self Sorting Insert function, Delete function, and Traversal functions.
class DoublyLL {
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
/*
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
*/
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
/*
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
*/
        //Traverse function, uses ofstream to pass data back to main
/*
        ofstream& traverseAscending(ofstream& outFile) {
                Node* curr = head;
                while (curr) {
                        outFile << curr->getName() << endl;
                        curr = curr->getNext();
                }
                return outFile;
        }
*/
        //Traverse function, uses ofstream to pass data back to main
/*
        ofstream& traverseDescending(ofstream& outFile) {
                Node* curr = tail;
                while (curr) {
                        outFile << curr->getName() << endl;
                        curr = curr->getPrev();
                }
                return outFile;
        }
*/
        ofstream& buildYearReadMe(ofstream& outFile) {
                Node* curr = tail;
                while (curr) {
                        outFile << "*  [" << curr->getCaseName() << "](" << curr->getDocketNum() << ".md)" << endl;
                        curr = curr->getPrev();
                }
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
};

//Helper function to convert text to all lower case
string toLower(string str) {
        for (size_t i = 0; i < str.length(); i++) {
                str[i] = tolower(str[i]);
        }
        return str;
}



int main() {
        ifstream inFile;
        inFile.open(inFileName);
        string ordNum, date, docketNum, caseName, url;
        DoublyLL* entryList = new DoublyLL;
        while (getline(inFile, ordNum, '\t')) {
                getline(inFile, date, '\t');
                getline(inFile, docketNum, '\t');
                getline(inFile, caseName, '\t');
                getline(inFile, url, '\n');
                entryList->insertBack(ordNum, date, docketNum, caseName, url);
        }
        inFile.close();
        ofstream outFile;
        outFile.open("readMe.txt");
        entryList->buildYearReadMe(outFile);
        outFile.close();

        Node* curr = entryList->getHead();
        string pageName;
        while (curr) {
                pageName = curr->getDocketNum() + ".md";
                outFile.open(pageName);
                curr->buildCasePage(outFile);
                outFile.close();
                curr = curr->getNext();
        }
        delete entryList;
        return 0;
}
