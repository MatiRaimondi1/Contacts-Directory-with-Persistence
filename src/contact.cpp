#include "contact.h"

Contact::Contact(string _name, string _telephone, string _mail): name(_name), telephone(_telephone), mail(_mail) {}

string Contact::getName() const {
    return name;
}

string Contact::getTelephone() const {
    return telephone;
}

string Contact::getMail() const {
    return mail;
}

void Contact::show() const {
    cout << name << " - " << telephone << " - " << mail << endl;
}

string Contact::toFileString() const {
    return name + "," + telephone + "," + mail;
}