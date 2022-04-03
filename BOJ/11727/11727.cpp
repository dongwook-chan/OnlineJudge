#include <iostream>
#include <cstring>

#define MAX_NO 1000
#define NOT_MEMOIZED -1
#define DIVISOR 10007

using namespace std;

unsigned int table[MAX_NO + 1];

int init_table() {
    memset(table + 1, NOT_MEMOIZED, sizeof(unsigned int) * MAX_NO);
}

unsigned int lookup(int n) {
    // base case
    switch(n) {
        case 1:
            return 1;
        case 2:
            return 3;
    }

    // memoized
    if(table[n] != NOT_MEMOIZED) return table[n];

    // not memoized
    table[n] = (lookup(n - 2) * 2 + lookup(n - 1)) % DIVISOR;
    return table[n];
}

int main() {
    init_table();

    int n;
    cin >> n;

    cout << lookup(n);

    return 0;
}