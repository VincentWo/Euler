// 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
template<typename Container, typename Value_type> Container create_range(const Value_type& begin, const Value_type& end)
{
	Container con{};

	for (auto i = begin; i < end; ++i)
	{
		con.push_back(i);
	}
	return con;
}

int main()
{
	auto range = create_range<std::vector<unsigned long long>>(1, 101);

	auto square_sum = std::accumulate(range.cbegin(), range.cend(), 0, [](auto& lhs, auto& rhs)
	{
		return lhs + std::pow(rhs, 2);
	});

	auto sum = std::accumulate(range.cbegin(), range.cend(), 0ull);
	auto square_of_sum = sum * sum;

	std::cout << (square_of_sum - square_sum);
	std::cin.get();

    return 0;
}

