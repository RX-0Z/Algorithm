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

void problem::problem1()
{
    string message = "Let's go!";

    cout << "3" << '\n' << "2" << '\n' << "1" << endl;
    cout << message << endl;

    return;
}

void problem::problem2()
{
    int angle1;
    int angle2;
    cin >> angle1 >> angle2;

    int sum_angle = (angle1 + angle2) - (360 * ((angle1 + angle2) / 360));
    cout << sum_angle << endl;

    return;
}

void problem::problem3()
{
    int number;
    cin >> number;

    int answer = 0;

    for (int i = 0; i < number; i++) {
        answer += number % 100;
        number /= 100;
    }
    cout << answer << endl;

    return;
}

void problem::problem4()
{
    string code;
    cin >> code;
    string last_four_words = code.substr(code.size() - 4, 4);
    if (last_four_words == "_eye") {
        cout << "Ophthalmologyc";
    }
    else if (last_four_words == "head") {
        cout << "Neurosurgery";
    }
    else if (last_four_words == "infl") {
        cout << "Orthopedics";
    }
    else if (last_four_words == "skin") {
        cout << "Dermatology";
    }
    else {
        cout << "direct recommendation";
    }

    return;
}