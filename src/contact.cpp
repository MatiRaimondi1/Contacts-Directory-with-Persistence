/// @file contact.cpp
/// @brief Implements the Contact class.

#include "contact.h"

/**
* @brief Constructs a Contact object.
* @param name The name of the contact.
* @param telephone The phone number of the contact.
* @param mail The email address of the contact.
*/
Contact::Contact(string _name, string _telephone, string _mail): name(_name), telephone(_telephone), mail(_mail) {}

/**
* @brief Gets the contact's name.
* @return The name of the contact.
*/
string Contact::getName() const {
    return name;
}

/**
* @brief Gets the contact's phone number.
* @return The phone number of the contact.
*/
string Contact::getTelephone() const {
    return telephone;
}

/**
* @brief Gets the contact's email address.
* @return The email address of the contact.
*/
string Contact::getMail() const {
    return mail;
}

/**
* @brief Displays the contact's details.
*/
void Contact::show() const {
    cout << name << " - " << telephone << " - " << mail << endl;
}

/**
* @brief Converts the contact's details into a formatted string for file storage.
* @return A string containing the contact's information in a file-friendly format.
*/
string Contact::toFileString() const {
    return name + "," + telephone + "," + mail;
}