#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "PhoneBook.hpp"

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

#endif