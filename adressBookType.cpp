#include "addressBookType.h"

// Add new entry interactively
void addressBookType::addEntry() {
    extPersonType newPerson;
    // Get user input for newPerson (e.g., name, birthday, address)
    std::cout << "Enter first name: ";
    std::string firstName;
    std::cin >> firstName;
    newPerson.setFirstName(firstName);
    // Continue collecting data for newPerson...

    insertLast(newPerson); // Add the new person to the linked list
}

// Remove entry based on first and last name
void addressBookType::removeEntry(const std::string& firstName, const std::string& lastName) {
    extPersonType personToDelete;
    personToDelete.setFirstName(firstName);
    personToDelete.setLastName(lastName);
    deleteNode(personToDelete); // Use deleteNode from the orderedLinkedList
}

// Save updated information back to the file
void addressBookType::saveToFile(const std::string& filename) {
    std::ofstream outfile(filename);
    for (auto it = begin(); it != end(); ++it) {
        outfile << *it << std::endl; // Ensure your extPersonType has an overloaded << operator
    }
    outfile.close();
}
