#include "linkedList.h"
#include "orderedLinkedList.h"
#include "extPersonType.h"
#include "addressBookType.h"
#include <iostream>
#include <fstream>  // For file handling
using namespace std;

int main() {
    // Implement the logic to load data from AddressBookData.txt 
    // and use the linked list-based addressBookType

    return 0;
}

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
    ifstream inFile;
    inFile.open(R"(AddressBookData.txt)");
    if (!inFile) {
        cerr << "Unable to open file AddressBookData.txt";
        exit(1);   // Call system to stop if file doesn't open
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
    int main() {
        addressBookType myAddressBook;
        // Initialize and load existing data...

        bool running = true;
        while (running) {
            int choice;
            std::cout << "1. Add Entry\n2. Remove Entry\n3. Exit\n";
            std::cin >> choice;

            switch (choice) {
            case 1:
                myAddressBook.addEntry();
                break;
            case 2: {
                std::string firstName, lastName;
                std::cout << "Enter first name: ";
                std::cin >> firstName;
                std::cout << "Enter last name: ";
                std::cin >> lastName;
                myAddressBook.removeEntry(firstName, lastName);
                break;
            }
            case 3:
                myAddressBook.saveToFile("AddressBookData.txt"); // Save before exit
                running = false;
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
            }
        }
        return 0;
    }
}