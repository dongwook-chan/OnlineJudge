#include <iostream>
#include <cstring>

#define MAX_NO 100
#define NOT_MEMOIZED -1
#define DIVISOR 1000000000

using namespace std;

unsigned int table[MAX_NO + 1][10];
void init_table() {
    memset(table, NOT_MEMOIZED, sizeof(table));
}

unsigned int lookup(int n, int m) {
    // base case
    if(n == 1) {
        switch(m) {
            case 0:
                return 0;
            default:
                return 1;
        }
    }

    // memoized
    if(table[n][m] != NOT_MEMOIZED) return table[n][m];

    // not memoized
    switch(m) {
        case 0:
            table[n][m] = lookup(n - 1, 1);
            break;
        case 9:
            table[n][m] = lookup(n - 1, 8);
            break;
        default:
            table[n][m] = lookup(n - 1, m - 1);
            table[n][m] += lookup(n - 1, m + 1);
            table[n][m] %= DIVISOR;
            break;
    }
    return table[n][m];
}

int main() {
    init_table();

    int N;
    cin >> N;

    unsigned int ans = lookup(N, 0);
    for(int digit = 1; digit <= 9; ++digit) {
        ans += lookup(N, digit);
        ans %= DIVISOR;
    }
    cout << ans;

    return 0;
}