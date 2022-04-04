#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_SIZE 1000
#define NOT_MEMOIZED -1

using namespace std;

struct entry{
    unsigned int max;
    unsigned int len;
} table[MAX_SIZE][MAX_SIZE];

void init_table() {
    memset(table, NOT_MEMOIZED, sizeof(table));
}

unsigned int A[MAX_SIZE];

entry lookup(int n, int m) {
    // base case
    if(n == m) return {A[n], 1U};

    // memoized
    if(table[n][m].len != NOT_MEMOIZED) return table[n][m];

    // not memoized
    entry old_entry = lookup(n, m - 1);
    if(A[m] > old_entry.max) table[n][m] = {A[m], old_entry.len + 1U};
    else table[n][m] = old_entry;

    cout << n << ' ' << m << ": " << table[n][m] << endl;
    return table[n][m];
}

int main() {
    init_table();

    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unsigned int ans = 0;
    for(int i = 0; i < N; ++i) {
        ans = max(ans, lookup(i, N - 1).len);
    }

    cout << ans;

    return 0;
}