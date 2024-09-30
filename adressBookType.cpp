#include "addressBookType.h"
#include <iostream>
#include <algorithm>  // For std::swap

addressBookType::addressBookType(int size) {
    maxSize = size;
    length = 0;
    addressList = new extPersonType[maxSize];
}

addressBookType::~addressBookType() {
    delete[] addressList;
}

void addressBookType::initEntry(std::ifstream& infile) {
    extPersonType person;
    while (infile >> person && length < maxSize) {
        addEntry(person);
    }
}

void addressBookType::addEntry(const extPersonType& person) {
    if (length < maxSize) {
        addressList[length] = person;
        length++;
    }
    else {
        std::cerr << "Address book is full!\n";
    }
}

void addressBookType::findPerson(const std::string& lastName) const {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getLastName() == lastName) {
            addressList[i].print();
            return;
        }
    }
    std::cout << "Person not found!\n";
}

void addressBookType::findBirthdays(int month) const {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getBirthMonth() == month) {
            addressList[i].print();
        }
    }
}

void addressBookType::findRelations(const std::string& relation) const {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getRelation() == relation) {
            addressList[i].print();
        }
    }
}

void addressBookType::print() const {
    for (int i = 0; i < length; i++) {
        addressList[i].print();
    }
}

void addressBookType::sortEntries() {
    for (int current = 1; current < length; current++) {
        int index = current;
        bool placeFound = false;

        while (index > 0 && !placeFound) {
            if (addressList[index].getLastName() < addressList[index - 1].getLastName()) {
                std::swap(addressList[index], addressList[index - 1]);
                index--;
            }
            else {
                placeFound = true;
            }
        }
    }
}