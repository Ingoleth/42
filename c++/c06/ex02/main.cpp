#include <cstdlib>
#include <time.h>
#include <iostream>

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate (void)
{
	srand(time(NULL));
	int i = rand() % 3;

	std::cout << "Created a class of type " << static_cast <char> (i + 'A') << std::endl;
	switch (i)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	
	default:
		return new C;
	}
}

void identify (Base *p)
{
	if (dynamic_cast <A *> (p))
		std::cout << "Class A!\n";
	else if (dynamic_cast <B *> (p))
		std::cout << "Class B!\n";
	else
		std::cout << "Class C!\n";
}

int main( void )
{
	Base *ptr;
 
	ptr = generate();
	identify(ptr);
	delete ptr;
	return 0;
}
