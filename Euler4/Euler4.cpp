// Euler4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>


template<typename to_t,
	typename from_t> to_t lexical_cast(const from_t& src)
{
	std::stringstream ss;
	to_t return_val;
	ss << src;
	ss >> return_val;
	return return_val;
}

using std::cerr;
using std::cout;
using std::cin;

template <typename value_type> bool is_palindromic(const value_type&);
template <typename value_type, typename container = std::list<value_type>> container get_digits(value_type num);

int main(int argc, char* argv)
{
	if (is_palindromic(980084))
	{
		return 1;
	}
	long long biggest = 0;

	for (auto i = 100; i < 1000; ++i)
	{
		for (auto j = 100; j < 1000; ++j)
		{
			long long number = i * j;
			if(is_palindromic(number))
			{ 
				biggest = std::max(biggest, number);
			}
		}
	}
	cout << biggest << '\n';
	cin.get();
}


template<typename value_type> bool is_palindromic(const value_type& num)
{
	auto digits = get_digits(num);
	if(digits.size() % 2 != 0)
	{ 
		return false;
	}

	auto front = digits.cbegin();
	auto back = digits.crbegin();

	for (auto i = 0u; i < (digits.size() / 2); ++i)
	{
		if (*front != *back)
		{
			return false;
		}
		++front;
		++back;
	}
	return true;
}

template<typename value_type, typename container> container get_digits(value_type num)
{
	auto cont = container{};
	auto insert_iter = std::front_inserter(cont);

	do
	{
		*insert_iter = num % 10;
		num /= 10;
	} while (num != 0);

	return cont;
}