#include <iostream>
#include <string>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 750
int main( void )
{
	{
	std::cout << "Mandatory tests:\n";
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	}

	std::cout << "Custom tests:\n";

	std::cout << "Empty array tests:\n";
	Array<int> empty = Array<int>(0);
	try
	{
		empty[0];
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	std::cout << "\nInt array tests:\n";
	Array<int> array = Array<int>(5);
	for (int i = 0; i < array.size(); i++)
	{
		array[i] = i;
		std::cout << array[i] << '|';
	}
	std::cout << '\n';
	for (int i = 0; i < array.size(); i++)
	{
		array[i]++;
		std::cout << array[i] << '|';
	}
	try
	{
		array[6];
	}
	catch (const std::exception& e)
	{
		std::cout << "\nException: " << e.what() << '\n';
	}

	std::cout << "\nString tests:\n";
	Array<std::string> array_string = Array<std::string>(3);
	array_string[0] = "hello";
	array_string[1] = "world!";
	array_string[2] = ":D";
	for (int i = 0; i < array_string.size(); i++)
		std::cout << array_string[i] << ' ';
	std::cout << '\n';

	std::cout << "\nCopy array tests:\n";
	Array<std::string> copied_array = array_string;
	copied_array[1] = "mom!";
	for (int i = 0; i < copied_array.size(); i++)
		std::cout << copied_array[i] << ' ';
	std::cout << '\n';
	for (int i = 0; i < array_string.size(); i++)
		std::cout << array_string[i] << ' ';
	std::cout << '\n';

	return 0;
}