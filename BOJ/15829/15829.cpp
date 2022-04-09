#include <iostream>
#include <string>

#define DIVISOR 1234567891

using namespace std;

int main() {
    int L;
    string S;
    cin >> L >> S;

    long long sum = 0;
    int r = 1;
    for(int i = 0; i < L; ++i) {
        int a = S[i] - 'a' + 1;
        
        sum += ((long long)a * r) % DIVISOR;

        r = (r * 31L) % DIVISOR;
    }

    cout << sum;
    return 0;
}