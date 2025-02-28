#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "contact.h"
#include <vector>
#include <fstream>
#include <sstream>

class Directory {
    private:
        vector<Contact> contacts;

        void saveContacts();
        void loadContacts();

    public:
        Directory();

        void addContact();
        void showContacts() const;
        void searchContact() const;
        void removeContact();
};

#endif // DIRECTORY_H