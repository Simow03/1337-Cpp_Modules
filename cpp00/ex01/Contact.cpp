#include "Contact.hpp"

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

bool Contact::isEmpty() {
    return (firstName.empty() || lastName.empty() || nickName.empty() ||
        phoneNumber.empty() || darkestSecret.empty());
}
