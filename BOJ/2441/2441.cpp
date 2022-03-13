#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = N; i >= 1; --i)
        cout << string(N - i, ' ') << string(i, '*') << '\n';

    return 0;
}