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

void problem::problem3()
{
	// 인수(Factor) : 어떤 수를 나누어떨어지게 하는 수(약수와 같은 의미)
	// 소수(Prime Number) : 1보다 큰 자연수 중에서 1과 자기 자신만을 약수로 가지는 수
	// 소인수(Prime Factor) : 어떤 자연수의 '인수(약수)' 중에서 소수(PrimeNumber)인 것
	// 소인수분해 : 1보다 큰 자연수를 오직 소인수들의 곱으로만 나타내는 것

	// step1: 소인수분해
	// step2: 소인수 구하기
	// step3: 가장 큰 소인수 구하기

	unsigned int compositeNumber = 0;
	unsigned int primeFactor = 0;
	unsigned int remainder = 0;
	bool isPrimeNumber = false;
	unsigned int primeNumber = 0;

	cout << "Composite number:";
	cin >> compositeNumber;
	cout << endl;

	// 나누어지는 수들 중 가장 작은 값 찾기

	for (int i = 1; i <= compositeNumber; i++)
	{
		remainder = compositeNumber % i;
		cout << "compositeNumber:" << i << endl;

		// 소수 여부 확인
		if (0 == remainder && i > 1)
		{		
			for (int j = 1; j <= remainder; j++)
			{
				int count = 0;
				if (0 == remainder % j && j > 1)
				{									
					if (j == remainder)
					{
						isPrimeNumber = true;
						primeNumber = j;
					}
				}
			}			
		}		
	}

	if (!isPrimeNumber)
	{
		cout << "No prime numbers." << endl;
	}
	else
	{
		cout << "prime number:" << primeNumber << endl;
	}
}

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