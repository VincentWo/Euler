// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	for (unsigned long long i = 20; i < 1'000'000'000; i+=20)
	{
		for (auto j = 19; j > 1; --j)
		{
			if (i % j != 0)
			{
				goto fail;
			}
		}
		cout << i << '\n';
		break;
	fail:;
	}
	cin.get();
}

