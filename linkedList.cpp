#include "linkedList.h"

// Default constructor for linkedListIterator
template <class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = nullptr;
}

// Parameterized constructor for linkedListIterator
template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type>* ptr) {
    current = ptr;
}

// Overload dereferencing operator
template <class Type>
Type linkedListIterator<Type>::operator*() {
    return current->info;
}

// Overload pre-increment operator
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
    current = current->link;
    return *this;
}

// Overload equality operator
template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const {
    return (current == right.current);
}

// Overload not equal to operator
template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const {
    return (current != right.current);
}

// Linked list type methods
template <class Type>
linkedListType<Type>::linkedListType() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
bool linkedListType<Type>::isEmptyList() const {
    return (first == nullptr);
}

template <class Type>
void linkedListType<Type>::print() const {
    nodeType<Type>* current = first;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

template <class Type>
int linkedListType<Type>::length() const {
    return count;
}

template <class Type>
void linkedListType<Type>::destroyList() {
    nodeType<Type>* temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template <class Type>
linkedListType<Type>::~linkedListType() {
    destroyList();
}