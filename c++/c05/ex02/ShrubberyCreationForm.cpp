#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

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