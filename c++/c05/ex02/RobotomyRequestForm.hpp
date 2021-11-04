#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm( RobotomyRequestForm const &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		void executeForm() const;

	private:

};

#endif /* ******************************************* ROBOTOMYREQUESTFORM_H */