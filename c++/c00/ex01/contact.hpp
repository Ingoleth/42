#ifndef CONTACT_H
# define CONTACT_H
#include<iostream>
#include<string>

class contact
{
	private:

		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string darkestSecret;
		std::string phoneNumber;		
		void	printContactField(std::string field);
	public:

		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickame(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestSecret(std::string darkestSecret);
		bool	printContactInfo(void);
		bool	printContactName(int index);

};

#endif