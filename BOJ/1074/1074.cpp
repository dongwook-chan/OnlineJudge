#include <iostream>

using namespace std;

int N, r, c;
int tile_ctr;

bool is_in_quadrant (int y, int x, int n) {
    return (y <= r && r < y + n && x <= c && c < x + n);
}

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
    if(is_in_quadrant(y, x, nn)) {
        if(dq(y, x, nn)) return true;
    }
    else tile_ctr += nn * nn;

    if(is_in_quadrant(y, x + nn, nn)) {
        if(dq(y, x + nn, nn)) return true;
    }
    else tile_ctr += nn * nn;
    
    if(is_in_quadrant(y + nn, x, nn)) {
        if(dq(y + nn, x, nn)) return true;
    }
    else tile_ctr += nn * nn;
    
    if(is_in_quadrant(y + nn, x + nn, nn)) {
        if(dq(y + nn, x + nn, nn)) return true;
    }
    else tile_ctr += nn * nn;
    
    return false;
}

int main() {
    cin >> N >> r >> c;

    dq(0, 0, 1 << N);

    cout << tile_ctr;

    return 0;
}