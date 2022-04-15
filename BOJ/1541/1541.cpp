#include <iostream>
#include <string>
#include <cctype>
#include <deque>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_NUMBER_CTR 25
#define MAX_OPERATOR_CTR 25
#define DEBUG

using namespace std;

deque<int> numbers;
vector<char> operators;
int min_res = INT_MAX;

void bf(int i, vector<int> stack) {
    if(i == numbers.size()) {
    #ifdef DEBUG
        for(auto e : stack) {
            cout << e << ' ';
        }
        cout << endl;
    #endif
        while(stack.size() > 1) {
            int n2 = stack.back(); stack.pop_back();
            int op = stack.back(); stack.pop_back();
            int n1 = stack.back(); stack.pop_back();
            int res;
            if(op == '+') {
                res = n1 + n2;
            }
            else {
                res = n1 - n2;
            }
            stack.push_back(res);
        }
        min_res = min(min_res, stack.back());
        return;
    }

    stack.push_back(operators[i]);
    stack.push_back(numbers[i]);

    bf(i + 1, stack);
    while(stack.size() > 1) {
        int n2 = stack.back(); stack.pop_back();
        int op = stack.back(); stack.pop_back();
        int n1 = stack.back(); stack.pop_back();
        int res;
        if(op == '+') {
            res = n1 + n2;
        }
        else {
            res = n1 - n2;
        }
        stack.push_back(res);
        bf(i + 1, stack);
    }
}

int main() {
    string equation;
    cin >> equation;

    string number;
    for(char c : equation) {
        if(isdigit(c)) {
            number.push_back(c);
        }
        else {
            numbers.push_back(stoi(number));
            number.clear();
            operators.push_back(c);
        }
    }
    numbers.push_back(stoi(number));

    vector<int> stack(1, numbers.front());
    numbers.pop_front();

    bf(0, stack);

    cout << min_res;

    return 0;
}