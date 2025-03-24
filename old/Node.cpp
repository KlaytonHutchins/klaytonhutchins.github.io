#include "Node.h"
#include <fstream>
#include <iostream>

using namespace std;

template <typename T>
Node<T>::Node() {
	next = nullptr;
	prev = nullptr;
	data = nullptr;
}

template <typename T>
Node<T>::Node(T* initData) {
	next = nullptr;
	prev = nullptr;
	data = initData;
}

template <typename T>
Node<T>::~Node() {
	next = nullptr;
	prev = nullptr;
	delete data;
}

template <typename T>
void Node<T>::setData(T* d) {
	data = d;
}

template <typename T>
T* Node<T>::getData() {
	return data;
}

template <typename T>
void Node<T>::setNext(Node<T>* n) {
	next = n;
}

template <typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* p) {
	prev = p;
}

template <typename T>
Node<T>* Node<T>::getPrev() {
	return prev;
}

