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

int main()
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
	return 0;
}