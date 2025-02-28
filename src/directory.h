/// @file directory.h
/// @brief Defines the Directory class, which manages a list of contacts.

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "contact.h"
#include <vector>
#include <fstream>
#include <sstream>


/**
 * @class Directory
 * @brief Manages a collection of contacts.
 */
class Directory {
    private:
        vector<Contact> contacts; ///< List of contacts.

        /**
        * @brief Saves the contacts to a file.
        */
        void saveContacts();

        /**
        * @brief Loads contacts from a file.
        */
        void loadContacts();

    public:
        /**
        * @brief Constructor for Directory.
        */
        Directory();

        /**
        * @brief Adds a new contact to the directory.
        */
        void addContact();

        /**
        * @brief Displays all contacts stored in the directory.
        */
        void showContacts() const;

        /**
        * @brief Searches for a contact by name.
        */
        void searchContact() const;

        /**
        * @brief Removes a contact from the directory.
        */
        void removeContact();
};

#endif // DIRECTORY_H