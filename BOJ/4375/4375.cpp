#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n) {
        int r = 1 % n;
        for (int i = 0; i < n; ++i) {
            if (r == 0) {
                cout << i + 1 << '\n';
                break;
            }
            r = (r * 10 + 1) % n;
        }
    }

    return 0;
}