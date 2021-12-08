#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm( PresidentialPardonForm const &src);
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		void executeForm() const;

	private:

};

#endif /* ******************************************* PRESIDENTIALPARDONFORM_H */