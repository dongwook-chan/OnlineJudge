#include <iostream>
#include <cstring>

#define MAX_NO 90
#define NOT_MEMOIZED -1

using namespace std;

unsigned long long table[MAX_NO + 1][2];

void init_table() {
    memset(table, NOT_MEMOIZED, sizeof(table));
}

unsigned long long lookup(int n, int m) {
    // base case
    if(n == 1 && m == 0) return 0;
    if(n == 1 && m == 1) return 1;

    // memoized
    if(table[n][m] != NOT_MEMOIZED) return table[n][m];

    // not memoized
    table[n][m] = 0;
    table[n][m] += lookup(n-1, 0);
    if(m == 0) {
        table[n][m] += lookup(n-1, 1);
    }
    return table[n][m];
}

int main() {
    init_table();

    int N;
    cin >> N;

    cout << lookup(N, 0) + lookup(N, 1);

    return 0;
}