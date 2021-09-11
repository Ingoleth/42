#include "karen.hpp"
#include <iostream>

karen::karen(/* args */)
{
	(fnptr)[0] = &karen::debug;
	(fnptr)[1] = &karen::info;
	(fnptr)[2] = &karen::warning;
	(fnptr)[3] = &karen::error;
	inputOptions[0] = "DEBUG";
	inputOptions[1] = "INFO";
	inputOptions[2] = "WARNING";
	inputOptions[3] = "ERROR";
}

karen::~karen(){}

void karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n";
}

void karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n";
}

void karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

void karen::complain(std::string level)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inputOptions[i] == level)
		{
			(this->*fnptr[i])();
			return;
		}
	}
	std::cout << "Like seriously, don't waste my time with stupid things...\n";
}
