/// @file directory.cpp
/// @brief Implements the Directory class.

#include "directory.h"

/**
 * @brief Constructs a Directory object.
 */
Directory::Directory() {
    loadContacts();
}

/**
* @brief Saves the contacts to a file.
*/
void Directory::saveContacts() {
    ofstream file("contacts.data");
    if (!file) {
        cout << "Error saving contacts." << endl;
        return;
    }
    for (const auto& c : contacts) {
        file << c.toFileString() << endl;
    }
    file.close();
}

/**
* @brief Loads contacts from a file.
*/
void Directory::loadContacts() {
    ifstream file("contacts.data");
    if (!file) return;
    contacts.clear();
    string line, name, telephone, mail;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, telephone, ',');
        getline(ss, mail, ',');
        contacts.push_back(Contact(name, telephone, mail));
    }
    file.close();
}

/**
* @brief Displays all contacts stored in the directory.
*/
void Directory::showContacts() const {
    if (contacts.empty()) {
        cout << "You have no contacts saved." << endl;
        return;
    }
    cout << "Contact list:" << endl;
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ": ";
        contacts[i].show();
    }
}

/**
* @brief Adds a new contact to the directory.
*/
void Directory::addContact() {
    string name, telephone, mail;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter telephone: ";
    getline(cin, telephone);
    cout << "Enter mail: ";
    getline(cin, mail);
    contacts.push_back(Contact(name, telephone, mail));
    saveContacts();
    cout << "Contact added." << endl;
}

/**
* @brief Removes a contact from the directory.
*/
void Directory::removeContact() {
    showContacts();
    if (contacts.empty()) return;
    int index;
    cout << "Enter the index of the contact you want to remove: ";
    cin >> index;
    if (index < 1 || index > contacts.size()) {
        cout << "Invalid index." << endl;
        return;
    }
    contacts.erase(contacts.begin() + (index - 1));
    saveContacts();
    cout << "Contact removed." << endl;
}


/**
* @brief Searches for a contact by name.
*/
void Directory::searchContact() const {
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);
    for (const auto& c : contacts) {
        if (c.getName() == name) {
            cout << "Found: ";
            c.show();
            return;
        }
    }
    cout << "Contact not found." << endl;
}