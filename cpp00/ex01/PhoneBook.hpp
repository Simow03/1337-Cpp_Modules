#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

class Contact {
private:
    // Attributes
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;

public:
    // Constructor
    Contact();

    // Setter methods
    void setFirstName(std::string& firstNameInput);
    void setLastName(std::string& lastNameInput);
    void setNickname(std::string& nickNameInput);
    void setPhoneNumber(std::string& number);
    void setDarkestSecret(std::string& secret);
    
    // Getter methods
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
    
    // Check if contact is empty
    bool isEmpty();
};

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
    bool addContact(Contact &contact);
    void displayContacts();
    void displayContact(int index);
    int getContactCount();
};

#endif