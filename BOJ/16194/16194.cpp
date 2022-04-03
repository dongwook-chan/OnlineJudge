#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_NO 1000
#define NOT_MEMOIZED -1

using namespace std;

unsigned int table[MAX_NO + 1];
int N, P[MAX_NO + 1];

void init_table() {
    memset(table + 1, NOT_MEMOIZED, sizeof(int) * MAX_NO);
}

unsigned int lookup(int n) {
    // if memoized
    if(table[n] != NOT_MEMOIZED) return table[n];

    // if not memoized
    table[n] = P[n];
    for(int i = 1; i < n; ++i) {
        table[n] = min(table[n], lookup(i) + P[n - i]);
    }
    return table[n];
}

int main() {
    init_table();

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> P[i];
    }

    cout << lookup(N);

    return 0;
}