#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void	contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void	contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}
void	contact::setNickame(std::string nickname)
{
	this->nickname = nickname;
}
void	contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void	contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

bool	contact::printContactInfo(void)
{
	if (firstName.size() == 0)
		return (false);
	std::cout << "-------------\nContact info:\n-------------\n";
	std::cout << std::left;
	std::cout << std::setw(16) << "First name" << "= ";
	std::cout << firstName << std::endl;
	std::cout << std::setw(16) << "Surname" << "= ";
	std::cout << lastName << std::endl;
	std::cout << std::setw(16) << "Nickname" << "= ";
	std::cout << nickname << std::endl;
	std::cout << std::setw(16) << "Phone number" << "= ";
	std::cout << phoneNumber << std::endl;
	std::cout << std::setw(16) << "Darkest secret" << "= ";
	std::cout << darkestSecret << std::endl << std::endl;
	return (true);
}

void	contact::printContactField(std::string field)
{
	std::cout << std::right;
	std::cout << std::setw(10);
	if (field.size() <= 10)
		std::cout << field;
	else
		std::cout << '.';
}

bool	contact::printContactName(int index)
{
	if (firstName.size() == 0)
		return (false);
	std::cout << std::setiosflags(std::ios::right);
	std::cout << std::setw(10) << index;
	printContactField(firstName);
	printContactField(lastName);
	printContactField(nickname);
	std::cout << std::endl;
	return (true);
}
