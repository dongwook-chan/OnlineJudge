#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cout << string(' ', i) << string('*', 2 * (N - i) - 1) << '\n';
    }

    return 0;
}