#include "directory.h"

int main() {
    Directory directory;
    int option;

    do {
        cout << "-- Contacts --" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Show contacts" << endl;
        cout << "3. Search contact" << endl;
        cout << "4. Remove contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1: directory.addContact(); break;
            case 2: directory.showContacts(); break;
            case 3: directory.searchContact(); break;
            case 4: directory.removeContact(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid option." << endl;
        }
    } while (option != 5);

    return 0;
}