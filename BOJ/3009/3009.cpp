#include <iostream>

using namespace std;

int func (int z[]) {
    if (z[0] == z[1]) {
        return z[2];
    }
    else if (z[0] == z[2]) {
        return z[1];
    }
    else {
        return z[0];
    }
}

int main() {
    int x[3], y[3];
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    cout << func(x) << ' ' << func(y);

    return 0;
}