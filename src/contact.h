/// @file contact.h
/// @brief Defines the Contact class.

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
using namespace std;

/**
 * @class Contact
 * @brief Represents a contact with a name, phone number, and email.
 */
class Contact {
    private:
        string name; ///< Contact's name.
        string telephone; ///< Contact's phone number.
        string mail; ///< Contact's email address.

    public:
        /**
         * @brief Constructor for Contact.
         * @param name The name of the contact.
         * @param telephone The phone number of the contact.
         * @param mail The email address of the contact.
         */
        Contact(string _name, string _telephone, string _mail);

        /**
         * @brief Gets the contact's name.
         * @return The name of the contact.
         */
        string getName() const;

        /**
         * @brief Gets the contact's phone number.
         * @return The phone number of the contact.
         */
        string getTelephone() const;

        /**
         * @brief Gets the contact's email address.
         * @return The email address of the contact.
         */
        string getMail() const;

        /**
         * @brief Displays the contact's details.
         */
        void show() const;

        /**
         * @brief Converts the contact's details into a formatted string for file storage.
         * @return A string containing the contact's information in a file-friendly format.
         */
        string toFileString() const;
};

#endif // CONTACT_H