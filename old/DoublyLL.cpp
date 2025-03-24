#include "DoublyLL.h"

using namespace std;


template <typename T>
DoublyLL<T>::DoublyLL() {
        setHead(nullptr);
        setTail(nullptr);
        setSize(0);
}

template <typename T>
DoublyLL<T>::~DoublyLL() {
        Node<T>* curr = getHead();
        while (curr) {
                Node<T>* tempNext = curr->getNext();
                delete curr;
                curr = tempNext;
        }
        setSize(0);
}

template <typename T>
void DoublyLL<T>::insertFront(Node<T>* newNode) {
        if (!getHead()) {  //empty list
                setHead(newNode);
                setTail(newNode);
        } else {
                newNode->setNext(getHead());
                getHead()->setPrev(newNode);
                setHead(newNode);
        }
        size++;
}

template <typename T>
void DoublyLL<T>::insert(Node<T>* newNode) {
        if (!getHead()) {  //empty list
                setHead(newNode);
                setTail(newNode);
        } else if (newNode->getData()->compare(getHead()->getData()) < 0) {  //insert at head
                newNode->setNext(getHead());
                getHead()->setPrev(newNode);
                setHead(newNode);
        } else if (newNode->getData()->compare(getTail()->getData()) > 0) {  //insert at tail
                newNode->setPrev(getTail());
                getTail()->setNext(newNode);
                setTail(newNode);
        } else {  //insert somewhere in the middle of the list
                Node<T>* curr = getHead();
                while(curr) {  //loop through list to find insertion point
                        if (newNode->getData()->compare(curr->getData()) < 0) {  //insert before curr
                                newNode->setNext(curr);
                                newNode->setPrev(curr->getPrev());
                                if (curr->getPrev()) {
					curr->getPrev()->setNext(newNode);
				} else {
					setHead(newNode);
				}
                                curr->setPrev(newNode);
                                break;
                        }
                        curr = curr->getNext();
                }
        }
        size++;
}

template <typename T>
void DoublyLL<T>::insertBack(Node<T>* newNode) {
        if (!getHead()) {  //empty list
                setHead(newNode);
                setTail(newNode);
        } else {
                newNode->setPrev(getTail());
                getTail()->setNext(newNode);
                setTail(newNode);
        }
        size++;
}

template <typename T>
void DoublyLL<T>::deleteNode(Node<T>* nodeToDelete) {
	if (!nodeToDelete) return;
        Node<T>* curr = getHead();
        while (curr) {
                Node<T>* nextNode = curr->getNext();
                if (curr == nodeToDelete) {
                        if (curr->getPrev()) {  //if curr != head
                                curr->getPrev()->setNext(curr->getNext());
                        } else {  //curr == head, reassign head to the second node
                                setHead(curr->getNext());
                        }
                        if (curr->getNext()) {  //if curr != tail
                                curr->getNext()->setPrev(curr->getPrev());
                        } else {  //deleting tail, reassign tail to its previous node
                                setTail(curr->getPrev());
                        }
                        delete curr;
                        break;  //comment out if expecting duplicates and want to delete all instances
                }
                curr = nextNode;
        }
        size--;
}

template <typename T>
ofstream& DoublyLL<T>::traverseAscending(ofstream& outFile) {
        Node<T>* curr = getHead();
        while (curr) {
                // outFile << curr->getName() << endl;
                curr = curr->getNext();
        }
        return outFile;
}

template <typename T>
ofstream& DoublyLL<T>::traverseDescending(ofstream& outFile) {
        Node<T>* curr = getTail();
        while (curr) {
                // outFile << curr->getName() << endl;
                curr = curr->getPrev();
        }
        return outFile;
}

template <typename T>
void DoublyLL<T>::setHead(Node<T>* h) {
        head = h;
}

template <typename T>
Node<T>* DoublyLL<T>::getHead() {
        return head;
}

template <typename T>
void DoublyLL<T>::setTail(Node<T>* t) {
        tail = t;
}

template <typename T>
Node<T>* DoublyLL<T>::getTail() {
        return tail;
}

template <typename T>
void DoublyLL<T>::setSize(int s) {
        size = s;
}

template <typename T>
int DoublyLL<T>::getSize() {
        return size;
}

