#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

bool isPrintable(std::string input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (!isprint(input[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    PhoneBook PhoneBook;
    std::string command;

    std::cout << "~ WELCOME TO CRAPPY PHONEBOOK ~" << std::endl;
    std::cout << "Available commands : ADD, SEARCH, EXIT : " << std::endl;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        if (command == "EXIT")
            break ;
        else if (command == "ADD") {
            Contact newContact;
            std::string input;
            
            std::cout << "Enter First name : ";
            std::getline(std::cin, input);
            if (!isPrintable(input))
            {
                std::cout << "Error : Invalid character !" << std::endl;
                continue;
            }
            newContact.setFirstName(input);

            std::cout << "Enter Last name : ";
            std::getline(std::cin, input);
            if (!isPrintable(input))
            {
                std::cout << "Error : Invalid character !" << std::endl;
                continue;
            }
            newContact.setLastName(input);

            std::cout << "Enter Nickname : ";
            std::getline(std::cin, input);
            if (!isPrintable(input))
            {
                std::cout << "Error : Invalid character !" << std::endl;
                continue;
            }
            newContact.setNickname(input);

            std::cout << "Enter Phone Number : ";
            std::getline(std::cin, input);
            if (!isPrintable(input))
            {
                std::cout << "Error : Invalid character !" << std::endl;
                continue;
            }
            newContact.setPhoneNumber(input);

            std::cout << "Enter Darkest Secret : ";
            std::getline(std::cin, input);
            if (!isPrintable(input))
            {
                std::cout << "Error : Invalid character !" << std::endl;
                continue;
            }
            newContact.setDarkestSecret(input);

            if (PhoneBook.addContact(newContact))
                std::cout << "Contact added successfully !" << std::endl;
        }
        else if (command == "SEARCH") {
            if (PhoneBook.getContactCount() == 0) {
                std::cout << "PhoneBook is empty !" << std::endl;
                continue ;
            }

            PhoneBook.displayContacts();

            std::string indexStr;
            int index;
            std::cout << "Enter Contact index to view details : ";
            std::getline(std::cin, indexStr);

            index = atoi(indexStr.c_str());
            PhoneBook.displayContact(index);
        }
        else if (!command.empty()) {
            std::cout << "Invalid Command ! Use ADD, SEARCH, EXIT : " << std::endl;
        }
    }
    
    std::cout << "Bye !" << std::endl;
    return 0;
}