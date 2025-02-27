#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
using namespace std;

class Contact {
    private:
        string name;
        string telephone;
        string mail;

    public:
        Contact(string _name, string _telephone, string _mail);

        string getName() const;
        string getTelephone() const;
        string getMail() const;
        void show() const;
        string toFileString() const;
};

#endif