#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include "extPersonType.h"
#include <fstream>

class addressBookType {
private:
    extPersonType* addressList;  // Dynamic array of extPersonType objects
    int length;                  // Current number of entries
    int maxSize;                 // Maximum number of entries

public:
    addressBookType(int size = 500);    // Constructor
    ~addressBookType();                 // Destructor

    void initEntry(std::ifstream& infile);  // Initialize from file
    void addEntry(const extPersonType& person);  // Add entry to the address book
    void findPerson(const std::string& lastName) const;  // Find person by last name
    void findBirthdays(int month) const;  // Find people by birth month
    void findRelations(const std::string& relation) const;  // Find people by relationship
    void print() const;  // Print all entries
    void sortEntries();   // Sort the entries alphabetically by last name
};

#endif