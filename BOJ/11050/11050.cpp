#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_NO 10
#define NOT_MEMOIZED INT_MAX

using namespace std;

int table[MAX_NO + 1][MAX_NO + 1];
int N, K;

void init_table() {
    for(int i = 0; i <= MAX_NO; ++i) {
        fill(table[i], table[i] + MAX_NO + 1, NOT_MEMOIZED);
    }
}

int lookup(int n, int k) {
    if(k == 0 || k == n) return 1;

    if(table[n][k] != NOT_MEMOIZED) return table[n][k];

    table[n][k] = lookup(n - 1, k - 1) + lookup(n - 1, k);
    return table[n][k];
}

int main() {
    init_table();

    cin >> N >> K;

    cout << lookup(N, K);

    return 0;
}