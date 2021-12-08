#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm( ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		void executeForm() const;

	private:

};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */