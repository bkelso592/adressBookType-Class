#include "extPersonType.h"
#include <iostream>
#include <iomanip>
#include <string>

extPersonType::extPersonType() {
    // Default constructor implementation
    firstName = "";
    lastName = "";
    birthMonth = 0;
    birthDay = 0;
    birthYear = 0;
    address = "";
    city = "";
    state = "";
    zip = "";
    phoneNumber = "";
    relation = "";
}

void extPersonType::print() const {
    std::cout << "Name: " << firstName << " " << lastName << "\n"
        << "Birthday: " << std::setw(2) << std::setfill('0') << birthMonth << "/"
        << std::setw(2) << std::setfill('0') << birthDay << "/"
        << birthYear << "\n"
        << "Address: " << address << ", " << city << ", " << state << " " << zip << "\n"
        << "Phone: " << phoneNumber << "\n"
        << "Relation: " << relation << "\n\n";
}

std::string extPersonType::getLastName() const {
    return lastName;
}

int extPersonType::getBirthMonth() const {
    return birthMonth;
}

std::string extPersonType::getRelation() const {
    return relation;
}

// Overload >> operator to read from file
std::istream& operator>>(std::istream& is, extPersonType& person) {
    // Read in a person's data from the file
    if (is) {
        is >> person.firstName >> person.lastName;
        is >> person.birthMonth >> person.birthDay >> person.birthYear;

        is.ignore();  // Ignore the newline after reading birthYear
        std::getline(is, person.address);
        std::getline(is, person.city);
        is >> person.state >> person.zip >> person.phoneNumber;

        is.ignore();  // Ignore the newline after reading phoneNumber
        std::getline(is, person.relation);
    }

    return is;
}