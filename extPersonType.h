#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include <string>

class extPersonType {
private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phoneNumber;
    std::string relation;

public:
    extPersonType();  // Default constructor

    void print() const;  // Print person details
    std::string getLastName() const;
    int getBirthMonth() const;
    std::string getRelation() const;

    // Overload >> operator to read from file
    friend std::istream& operator>>(std::istream& is, extPersonType& person);
};

#endif