#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;

public:

    Contact();

    void setFirstName(std::string firstNameInput);
    void setLastName(std::string lastNameInput);
    void setNickname(std::string nickNameInput);
    void setPhoneNumber(std::string number);
    void setDarkestSecret(std::string secret);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

    bool isEmpty();
};

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