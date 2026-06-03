#include "problem.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;

void problem::problem2()
{
	//fibonacci sequence
	int result = 0;
	int index = 0;
	int total = 0;
	int breakCondion = 4000000;

	cout << "pibonacci index :";
	cin >> index;

	for (size_t i = 0; i <= index; i++)
	{
		result = fibonacci(i);
		
		if (result > breakCondion) break;

		if (0 == result % 2)
		{
			cout << result << " ";
			total += result;		
		}		
	}

	cout << endl;
	cout << "total:" << total;
}

int problem::fibonacci(int n)
{	
	if (0 >= n)
	{
		return 0;
	}

	if (1 == n)
	{		
		return 1;
	}		
	
	//cout << n << " ";
	return fibonacci(n-1) + fibonacci(n-2);
}

void problem::problem1()
{
	int number = 1000;
	int total = 0;

	while (number)
	{
		number--;

		if (number % 3 == 0)
		{
			total += number;
		}
		else if (number % 5 == 0)
		{
			total += number;
		}
	}

	cout << "total : " << total << endl;
}