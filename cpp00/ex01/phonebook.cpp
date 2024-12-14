#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
    currentIndex = 0;
    totalContacts = 0;
}

int PhoneBook::getContactCount() {
    return totalContacts;
}

bool PhoneBook::addContact(Contact contact) {
    if (contact.isEmpty()) {
        std::cout << "Error : contact is empty !" << std::endl;
        return false;
    }
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % MAX_CONTACTS;
    if (totalContacts < MAX_CONTACTS)
        totalContacts++;
    return true;
}

std::string PhoneBook::truncateText(const std::string text) {
    if (text.length() <= 10)
        return text;
    return text.substr(0, 9) + ".";
}

void PhoneBook::displayContacts() {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nick Name" << std::endl;
    for (int i = 0; i < totalContacts; i++) {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncateText(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateText(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateText(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index) {
    if (index <= 0 || index > totalContacts) {
        std::cout << "Error : invalid index !" << std::endl;
        return ;
    }
    Contact& contact = contacts[index - 1];
    std::cout << "First Name : " << contact.getFirstName() << std::endl;
    std::cout << "Last Name : " << contact.getLastName() << std::endl;
    std::cout << "Nick Name : " << contact.getNickname() << std::endl;
    std::cout << "Darkest Secret : " << contact.getDarkestSecret() << std::endl;
    std::cout << "Phone Number : " << contact.getPhoneNumber() << std::endl;
}
