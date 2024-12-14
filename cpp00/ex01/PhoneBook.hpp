#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
#include "Contact.hpp"


class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int currentIndex;
    int totalContacts;

    std::string truncateText(const std::string text);

public:
    PhoneBook();

    bool addContact(Contact contact);
    void displayContacts();
    void displayContact(int index);
    int getContactCount();
};

#endif