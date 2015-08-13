// 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <type_traits>
#include <iostream>

template<typename int_type> typename std::enable_if<std::is_integral<int_type>::value, bool>::type is_prime(int_type num)
{
	if (num % 2 == 0)
	{
		if (num == 2)
		{
			return true;
		}
		return false;
	}

	for (int i = 3; i*i <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	while (true)
	{
		long long number;
		std::cin >> number;
		if (!std::cin) return 0;
		std::cout << (is_prime(number) ? "true\n" : "false\n");
	}
}

