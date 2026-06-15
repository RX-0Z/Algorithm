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
#include <chrono>
#include <thread> // 예제용 가짜 지연을 위해 사용

using namespace std;

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
	return fibonacci(n - 1) + fibonacci(n - 2);
}

void problem::problem3()
{
	// 인수(Factor) : 어떤 수를 나누어떨어지게 하는 수(약수와 같은 의미)
	// 소수(Prime Number) : 1보다 큰 자연수 중에서 1과 자기 자신만을 약수로 가지는 수
	// 소인수(Prime Factor) : 어떤 자연수의 '인수(약수)' 중에서 소수(PrimeNumber)인 것
	// 소인수분해 : 1보다 큰 자연수를 오직 소인수들의 곱으로만 나타내는 것

	// step1: 소인수분해
	// step2: 소인수 구하기
	// step3: 가장 큰 소인수 구하기

	unsigned long long compositeNumber = 0;
	unsigned long long remainder = 0;
	unsigned long long primeNumber = 0;

	vector<unsigned long long> primeNumbers;
	vector<unsigned long long> factors;

	cout << "Composite number:";
	cin >> compositeNumber;
	cout << endl;

	// 나누어지는 수들 중 가장 큰 값 찾기
	for (int i = 1; i <= compositeNumber; i++)
	{
		remainder = compositeNumber % i;

		if (0 == remainder && (i % 2 != 0) && i != 0)
		{
			factors.push_back(i);
		}
	}

	// 소수 여부 확인
	for (int prime : factors)
	{
		for (int i = 1; i <= prime; i++)
		{
			remainder = prime % i;

			if (0 == remainder && i != prime && i != 1)
			{
				break;
			}

			if (0 == remainder && i == prime && i != 1)
			{
				primeNumbers.push_back(i);
			}
		}
	}

	// 가장 큰 수 찾기
	int maxPrimeNumber = 0;
	if (!primeNumbers.empty())
	{
		for (int prime : primeNumbers)
		{
			maxPrimeNumber = max(maxPrimeNumber, prime);
		}
	}

	cout << "maxPrimeNumber : " << maxPrimeNumber << endl;
}

bool problem::is_palindrome(unsigned int n)
{
	// 회문수를 판단하는 함수	
	bool isPalindrome = true;

	// 들어온 매개변수 (Parameter)가 몇자리 수인가?
	string number = to_string(n);
	unsigned int digit_length = number.size();
	
	unsigned int centerNumber = 0;
	vector<unsigned int> left_vec;
	vector<unsigned int> right_vec;

	// 홀수 일때
	if (0 != digit_length % 2)
	{
		//중간 숫자 
		unsigned int centerIndex = digit_length / 2;
		char middle = number[centerIndex];

		centerNumber = static_cast<unsigned int>(middle - '0');
		cout << "centerNumber:" << centerNumber << endl;

		for (int i = 0; i <= centerIndex; i++)
		{
			left_vec.push_back(stoi(number.substr(i, 1)));
		}

		for (auto var : left_vec)
		{
			cout << var << " ";
		}
		cout << endl;		

		for (int j = digit_length - 1; j > 0; j--)
		{
			right_vec.push_back(number[j] - '0');
		}

		for (auto var : right_vec)
		{
			cout << var << " ";
		}
		cout << endl;

		if (left_vec.size() == right_vec.size())
		{
			for (int k = 0; k < centerIndex; k++)
			{
				if (left_vec[k] != right_vec[k])
				{
					cout << "not palindrome!" << endl;
					isPalindrome = false;
				}
			}
		}
		else
		{
			cout << "wrong!" << endl;
		}
	}
	// 짝수 일때 
	else
	{
		//중간 숫자 
		unsigned int centerIndex = digit_length / 2;
		char middle = number[centerIndex];

		centerNumber = static_cast<unsigned int>(middle - '0');
		cout << "centerNumber:" << centerNumber << endl;

		for (int i = 0; i < centerIndex; i++)
		{
			left_vec.push_back(stoi(number.substr(i, 1)));
		}

		for (auto var : left_vec)
		{
			cout << var << " ";
		}
		cout << endl;

		for (int j = digit_length - 1; j > 0; j--)
		{
			right_vec.push_back(number[j] - '0');
		}

		for (auto var : right_vec)
		{
			cout << var << " ";
		}
		cout << endl;

		if (left_vec.size() == right_vec.size())
		{
			for (int k = 0; k < centerIndex; k++)
			{
				if (left_vec[k] != right_vec[k])
				{
					cout << "not palindrome!" << endl;
					isPalindrome = false;
				}
			}
		}
		else
		{
			cout << "wrong!" << endl;
		}
	}	
	cout << boolalpha << "isPalindrome:" << isPalindrome << endl;
	return isPalindrome;
}

void problem::problem4()
{
	// 대칭수 또는 회문수(palindromic number) : 앞에서부터 읽을 때와 뒤에서부터 읽을 때 완전히 같은 숫자

	unsigned int num1 = 0;
	unsigned int num2 = 0;
	unsigned int multiply_result = 0;
	unsigned int max_palindrome = 0;

	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			multiply_result = i * j;

			if (is_palindrome(multiply_result))
			{
				max_palindrome = max(max_palindrome, multiply_result);
				cout << "palindrome: " << multiply_result << endl;
			}
		}
	}
}