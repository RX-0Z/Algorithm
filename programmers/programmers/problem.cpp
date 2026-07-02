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

vector<int> problem5(vector<string> cpr) {
    vector<int> answer = { 0, 0, 0, 0, 0 };
    vector<string> basic_order = { "check", "call", "pressure", "respiration", "repeat" };

    for (int i = 0; i < cpr.size(); i++) {
        for (int j = 0; j < basic_order.size(); j++) {
            if (cpr[i] == basic_order[j]) {
                answer[i] = j + 1;
                break;
            }
        }
    }

    return answer;
}

int problem6(int storage, int usage, vector<int> change) {
    int total_usage = 0;
    for (int i = 0; i < change.size(); i++) {
        usage += (usage * change[i] / 100);
        total_usage += usage;
        if (total_usage > storage) {
            return i;
        }
    }
    return -1;
}

int func1(int num) {
    if (0 > num) {
        return 0;
    }
    else {
        return num;
    }
}

int func2(int num) {
    if (num > 0) {
        return 0;
    }
    else {
        return num;
    }
}

int func3(vector<string> station) {
    int num = 0;
    for (int i = 0; i < station.size(); i++) {
        if (station[i] == "Off") {
            num += 1;
        }
    }
    return num;
}

int func4(vector<string> station) {
    int num = 0;
    for (int i = 0; i < station.size(); i++) {
        if (station[i] == "On") {
            num += 1;
        }
    }
    return num;
}

int problem7(int seat, vector<vector<string>> passengers) {
    int num_passenger = 0;
    for (int i = 0; i < passengers.size(); i++) {
        num_passenger += func4(passengers[i]);
        num_passenger -= func3(passengers[i]);
    }
    int answer = func1(seat - num_passenger);
    return answer;
}

string problem8(string nickname) {
    string answer = "";
    for (int i = 0; i < nickname.size(); i++) {
        if (nickname[i] == 'l') {
            answer += "I";
        }
        else if (nickname[i] == 'w') {
            answer += "vv";
        }
        else if (nickname[i] == 'W') {
            answer += "VV";
        }
        else if (nickname[i] == 'O') {
            answer += "0";
        }
        else {
            answer += nickname[i];
        }
    }
    for (int i = answer.size(); i <= 3; i++) {
        answer += "o";
    }
    if (answer.size() > 8) {
        answer = answer.substr(0, 8);
    }
    return answer;
}

int problem9(void) {
    int a;
    int c;
    cin >> a >> c;

    int b_square = (c * c) - (a * a);
    cout << b_square << endl;
    return 0;
}

int problem10(void) {
    int year, answer;
    string age_type;
    cin >> year >> age_type;

    if (age_type == "Korea") {
        answer = 2030 - year + 1;
    }
    else if (age_type == "Year") {
        answer = 2030 - year;
    }

    cout << answer << endl;
    return 0;
}

#include <iostream>

using namespace std;

int problem11(void) {
    int start;
    int before;
    int after;
    cin >> start >> before >> after;

    int money = start;
    int month = 1;

    while (money < 70) {
        money += before;
        month++;
    }
    while (money < 100) {
        money += after;
        month++;
    }
    cout << month << endl;
    return 0;
}

vector<int> problem12(string route) {
    int east = 0;
    int north = 0;
    vector<int> answer(2);
    for (int i = 0; i < route.length(); i++) {
        switch (route[i]) {
        case 'N':
            north++;
            break;
        case 'S':
            north--;
            break;
        case 'E':
            east++;
            break;
        case 'W':
            east--;
            break;
        }
    }
    answer[0] = east;
    answer[1] = north;
    return answer;
}