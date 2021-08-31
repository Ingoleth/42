#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include "contact.hpp"

class phoneBook
{
	private:

		typedef enum e_fields
		{
			firstname,
			surname,
			nickname,
			phone,
			darkestSecret
		}			t_fields;

		contact contact_list[8];
		int current_contact;

		void	addField(contact &aux, int field);

	public:

		phoneBook();
		void	query();
		void	add();
		void	search();
};

#endif