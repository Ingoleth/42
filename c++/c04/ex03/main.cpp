#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	IMateriaSource* src = new MateriaSource();
	AMateria *tmp;
	tmp = new Ice();
	std::cout << "\nThe second call to learnMateria does nothing since the memory address of the materia to learn is the same as the one already known\n";
	src->learnMateria(tmp);
	src->learnMateria(tmp);
	src->displayKnownMateria();
	std::cout << "\nAll ice materias are properly learnt\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->displayKnownMateria();
	std::cout << "\nCure materia is not learnt because all materias are known!\n";
	tmp = new Cure ();
	src->learnMateria(tmp);
	delete tmp;
	src->displayKnownMateria();

	IMateriaSource *src2 = src->clone();
	delete src;
	std::cout << "\nMateriaSrc is properly (deep) copied:\n";
	src2->displayKnownMateria();

	std::cout << "----------------\nCharacter tests: \n----------------\n";
	Character bob("bob");
	Character bob2("bob2");

	tmp = src2->createMateria("ice");
	bob.equip(tmp);
	bob.equip(tmp);
	bob2 = bob;
	bob.display_info();
	std::cout << std::endl;
	bob.unequip(0);
	bob.display_info();
	bob.unequip(0);
	std::cout << std::endl;
	delete (tmp);
	bob2.display_info();
}

