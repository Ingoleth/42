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
	src->displayKnownMateria();

	IMateriaSource* src2 = src;
	delete src;
	std::cout << "\nMateriaSrc is properly (deep) copied:\n";
	src2->displayKnownMateria();
	delete tmp;
}

