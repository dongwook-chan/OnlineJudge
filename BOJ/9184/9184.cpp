#include <iostream>
#include <cstring>

using namespace std;

int cached[21][21][21];
int w (int a, int b, int c);

int memoization (int a, int b, int c) {
    if (cached[a][b][c] != -1) {
        return cached[a][b][c];
    }
    else {
        return cached[a][b][c] = w (a, b, c);
    }
}

int w (int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    if (a > 20 or b > 20 or c > 20) {
        return memoization (20, 20, 20);
    }

    if (a < b and b < c) {
        return memoization (a, b, c - 1) + \
            memoization (a, b - 1, c - 1) - \
            memoization (a, b - 1, c);
    }

    return memoization (a-1, b, c) + \
        memoization (a-1, b-1, c) + \
        memoization (a-1, b, c-1) - \
        memoization (a-1, b-1, c-1);
}

int main() {
    memset (cached, -1, sizeof(cached));

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b && b == c && c == -1) {
            break;
        }

        int ans = w (a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
    }

    return 0;
}