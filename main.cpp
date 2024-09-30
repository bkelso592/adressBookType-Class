#include <iostream>
#include <fstream>
#include <string>
#include "addressBookType.h"

void showMenu() {
    std::cout << "On-line Address Book\n";
    std::cout << "Select an option:\n";
    std::cout << "1 – Display all entries in the address Book.\n";
    std::cout << "2 – Display an entry by a person’s name.\n";
    std::cout << "3 – Display all entries with a given birth month.\n";
    std::cout << "4 – Display all entries with a given relationship tag (Business, Friend, Family).\n";
    std::cout << "5 – Quit\n";
}

int main() {
    addressBookType addressBook;

    // Read data from the AddressBookData.txt resource file
    std::ifstream infile("AddressBookData.txt");

    if (!infile) {
        std::cerr << "Error: Could not open the AddressBookData.txt file." << std::endl;
        return 1;
    }

    // Initialize the addressBook from the file
    addressBook.initEntry(infile);
    infile.close();

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addressBook.print();
            break;
        case 2: {
            std::string lastName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            addressBook.findPerson(lastName);
            break;
        }
        case 3: {
            int month;
            std::cout << "Enter birth month: ";
            std::cin >> month;
            addressBook.findBirthdays(month);
            break;
        }
        case 4: {
            std::string relation;
            std::cout << "Enter relationship (Business, Friend, Family): ";
            std::cin >> relation;
            addressBook.findRelations(relation);
            break;
        }
        case 5:
            std::cout << "Quitting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}