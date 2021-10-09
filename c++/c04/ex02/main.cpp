
#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main( void )
{
	{
		std::cout << "\n------------\nBrain tests:\n------------\n";
		Brain copy;
		{
			Brain test;
			test.setIdea("I like bones!");
			test.setIdea("I diggy diggy hole!");
			test.setIdea("Waves tail");
			test.setIdea("Squirrel!!!");
			copy = test;
			std::cout << test;
		}
				std::cout << "-----\n";
		std::cout << copy;
	}
	{
		std::cout << "\n-------------\nAnimal tests:\n-------------\n";
		Cat TotallyNotPaprika;
		{
			Cat Paprika;
			Paprika.think("I want food");
			Paprika.think("If I don't move they can't see me...");
			Paprika.think("They can... RUUUUUUN!");
			Paprika.thinkOutloud();
			TotallyNotPaprika = Paprika;
		}
		std::cout << "-----\n";
		TotallyNotPaprika.thinkOutloud();
	}
	std::cout << "\n\n\n------------\nArray tests:\n------------\n";
	Animal *array[100];
	int i = 0;
	while(i < 50)
		array[i++] = new Cat();
	while(i < 100)
		array[i++] = new Dog();
	while (--i >= 0)
		delete(array[i]);
	return 0;
}