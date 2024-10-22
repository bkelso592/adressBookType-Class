#include "orderedLinkedList.h"

// Search for an item in the ordered linked list
template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const {
    nodeType<Type>* current = this->first;
    while (current != nullptr) {
        if (current->info == searchItem)
            return true;
        else if (current->info > searchItem)
            return false;
        current = current->link;
    }
    return false;
}

// Insert a node at the beginning of the list
template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem) {
    // Since this is an ordered list, we should use insertLast or insert in order
    insertLast(newItem);
}

// Insert a node at the end of the list (preserves order)
template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (this->first == nullptr) {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else {
        nodeType<Type>* current = this->first;
        nodeType<Type>* trailCurrent = nullptr;
        while (current != nullptr && current->info < newItem) {
            trailCurrent = current;
            current = current->link;
        }
        if (trailCurrent == nullptr) {
            newNode->link = this->first;
            this->first = newNode;
        }
        else {
            trailCurrent->link = newNode;
            newNode->link = current;
        }
        if (current == nullptr)
            this->last = newNode;
        this->count++;
    }
}

// Delete a node from the ordered linked list
template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    if (this->first == nullptr) {
        cout << "Cannot delete from an empty list." << endl;
    }
    else {
        nodeType<Type>* current = this->first;
        nodeType<Type>* trailCurrent = nullptr;
        while (current != nullptr && current->info != deleteItem) {
            trailCurrent = current;
            current = current->link;
        }
        if (current == nullptr) {
            cout << "Item not found." << endl;
        }
        else {
            if (current == this->first)
                this->first = this->first->link;
            else
                trailCurrent->link = current->link;
            if (current == this->last)
                this->last = trailCurrent;
            delete current;
            this->count--;
        }
    }
}