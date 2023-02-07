#include <iostream>

using namespace std;

bool is_divisible_by_7[1000001];
bool is_divisible_by_11[1000001];
string hurra = "Hurra!";
string super = "Super!";
string wiwat = "Wiwat!";
string *expressions[1000001];

int main() {
    for (int m = 7; m <= 1000000; m += 7) {
        expressions[m] = &hurra;
    }
    for (int m = 11; m <= 1000000; m += 11) {
        if (expressions[m]) {
            expressions[m] = &wiwat;
        }
        else {
            expressions[m] = &super;
        }
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (expressions[i]) {
            cout << *expressions[i];
        }
        else {
            cout << i;
        }
        cout << '\n';
    }
}
