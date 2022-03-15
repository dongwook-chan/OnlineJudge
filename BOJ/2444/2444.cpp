#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N - 1; ++i) {
        cout << string(N - i - 1, ' ') << string(2 * i + 1, '*') << '\n';
    }
    cout << string(2 * N - 1, '*') << '\n';
    for(int i = 0; i < N - 1; ++i) {
        cout << string(i + 1, ' ') << string(2 * (N - i - 1) - 1, '*') << '\n';
    }

    return 0;
}