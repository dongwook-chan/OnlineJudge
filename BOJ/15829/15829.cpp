#include <iostream>
#include <string>

#define DIVISOR 1234567891

using namespace std;

int main() {
    int L;
    string S;
    cin >> L >> S;

    long long sum = 0;
    for(int i = 0; i < L; ++i) {
        int a = S[i] - 'a' + 1;
        int r = 1;
        for(int j = 0; j < i; ++j) {
            r = (r * 31L) % DIVISOR;
        }
        sum += ((long long)a * r) % DIVISOR;
    }

    cout << sum;
    return 0;
}