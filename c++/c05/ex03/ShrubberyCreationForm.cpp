#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", "unnamed", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form("ShrubberyCreationForm", src.getTarget(), 145, 137) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const &)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	void ShrubberyCreationForm::executeForm() const
	{
		std::string	target = getTarget();
		std::ofstream file(target.append("_shrubbery").c_str());
		
		file << "    \\|/                \\|/\n"
				"   --0--              --0--\n"
				"    /|\\                /|\\\n"
				"   //|\\\\              //|\\\\\n"
				"  ///|\\\\\\            ///|\\\\\\\n"
				" ////|\\\\\\\\          ////|\\\\\\\\\n"
				"/////|\\\\\\\\\\        /////|\\\\\\\\\\\n"
				"    |||                |||\n"
				"____|||____        ____|||____\n";
		file.close();
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */