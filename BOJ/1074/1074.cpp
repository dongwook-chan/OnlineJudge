#include <iostream>

using namespace std;

int N, r, c;
int tile_ctr;

bool dq (int y, int x, int n) {
    if(n == 1) {
        if(y == r && x == c) {
            return true;
        }
        ++tile_ctr;
        return false;
    }

    // divide
    int nn = n / 2;
    if(dq(y, x, nn)) return true;
    if(dq(y, x + nn, nn)) return true;
    if(dq(y + nn, x, nn)) return true;
    if(dq(y + nn, x + nn, nn)) return true;

    return false;
}

int main() {
    cin >> N >> r >> c;

    dq(0, 0, 1 << N);

    cout << tile_ctr;

    return 0;
}