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
#include "problem.h"

using namespace std;

int main()
{
	problem p;

	// 1. 시작 시간 기록
	auto start = chrono::high_resolution_clock::now();

	// 2. 측정할 로직
	//p.problem4();
	p.is_palindrome(1011);

	//3. 종료 시간 기록
	auto end = chrono::high_resolution_clock::now();

	auto duration_ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	std::cout << "실행 시간: " << duration_ms << " ms\n";
	return 0;
}