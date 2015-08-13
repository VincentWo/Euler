// 20.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"

template<int number> struct factorial
{
	enum { value = factorial < number - 1>::value };
};

template<1> struct factorial
{
	enum { value = 1 };
};

int main()
{
	std::cout << factorial<10>::value;
	std::cin.get();
}

