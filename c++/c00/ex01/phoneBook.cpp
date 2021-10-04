#include "phoneBook.hpp"

phoneBook::phoneBook()
{
	current_contact = 0;
}

void	phoneBook::addField(contact &aux, int field)
{
	std::string input;

	while (true)
	{
		std::getline(std::cin, input);
		if(input.size())
			break ;
		std::cout << "Empty inputs are not allowed; please try again..." << std::endl;
	}
	switch (field)
	{
	case firstname:
		aux.setFirstName(input);
		break;
	case surname:
		aux.setLastName(input);
		break;
	case nickname:
		aux.setNickame(input);
		break;
	case phone:
		aux.setPhoneNumber(input);
		break;
	case darkestSecret:
		aux.setDarkestSecret(input);
		break;
	default:
		break;
	}
}

void	phoneBook::query()
{
	std::string	instruction;

	while (true)
	{
		std::cout << "Awating instructions..." << std::endl;
		std::getline(std::cin, instruction);
		if (instruction == "ADD" || instruction == "add")
			add();
		else if (instruction == "SEARCH" || instruction == "search")
			search();
		else if (instruction == "EXIT" || instruction == "exit")
			break ;
	}
}

void	phoneBook::add()
{
	contact aux;

	std::cout << "------------------------" << std::endl;
	std::cout << "Creating a new contact: " << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "Please input contact first name:" << std::endl;
	addField(aux, firstname);
	std::cout << "Please input contact last name:" << std::endl;
	addField(aux, surname);
	std::cout << "Please input contact nickname:" << std::endl;
	addField(aux, nickname);
	std::cout << "Please input contact phone number:" << std::endl;
	addField(aux, phone);
	std::cout << "Please input contact darkest secret:" << std::endl;
	addField(aux, darkestSecret);
	contact_list[current_contact] = aux;
	if (current_contact != 7)
		current_contact++;
	else
		current_contact = 0;
}

void	phoneBook::search()
{
	int i;
	int index;
	std::string aux;

	i = -1;
	do
	{
		i++;
	} while (i < 8 && contact_list[i].printContactName(i));
	if (i == 0)
	{
		std::cout << "There are currently no contacts stored in the phone book." << std::endl;
		return ;
	}
	while (true)
	{
		std::cout << std::endl << "Please select a contact id:" << std::endl;
		std::getline(std::cin, aux);
		try
		{
			index = std::stoi(aux, nullptr, 10);
			if (index < 0 || index >= i)
				throw (1);
			break ;
		}
		catch(...)
		{
			std::cout << "Invalid contact id;";
		}
	}
	contact_list[index].printContactInfo();
}
