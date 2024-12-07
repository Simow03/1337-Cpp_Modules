#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
}

void Contact::setFirstName(std::string firstNameInput) {
    firstName = firstNameInput;
}
void Contact::setLastName(std::string lastNameInput) {
    lastName = lastNameInput;
}
void Contact::setNickname(std::string nickNameInput) {
    nickName = nickNameInput;
}
void Contact::setPhoneNumber(std::string numberInput) {
    phoneNumber = numberInput;
}
void Contact::setDarkestSecret(std::string secretInput) {
    darkestSecret = secretInput;
}

std::string Contact::getFirstName() {
    return firstName;
}
std::string Contact::getLastName() {
    return lastName;
}
std::string Contact::getNickname() {
    return nickName;
}
std::string Contact::getPhoneNumber() {
    return phoneNumber;
}
std::string Contact::getDarkestSecret() {
    return darkestSecret;
}
int PhoneBook::getContactCount() {
    return totalContacts;
}

bool Contact::isEmpty() {
    return (firstName.empty() || lastName.empty() || nickName.empty() ||
        phoneNumber.empty() || darkestSecret.empty());
}

PhoneBook::PhoneBook() {
    currentIndex = 0;
    totalContacts = 0;
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
