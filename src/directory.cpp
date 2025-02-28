#include "directory.h"

Directory::Directory() {
    loadContacts();
}

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

void Directory::addContact() {
    string name, telephone, mail;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter telephone: ";
    cin.ignore();
    getline(cin, telephone);
    cout << "Enter mail: ";
    cin.ignore();
    getline(cin, mail);
    contacts.push_back(Contact(name, telephone, mail));
    saveContacts();
    cout << "Contact added." << endl;
}

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