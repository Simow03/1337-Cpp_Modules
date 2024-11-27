#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
private:
    // Attributes
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int currentIndex;
    int totalContacts;

    //Truncate text
    std::string truncateText(const std::string &text);

public:
    //Constructor
    PhoneBook();

    // Methods
    void addContact(Contact &contact);
    void displayContacts();
    void displayContact(int index);
    int getContactCount();
};

#endif