#include <iostream>
#include <cstring>

#define MAX_NO 100000
#define DIVISOR 1000000009

using namespace std;

int table_[MAX_NO][3] = {
    {1, 0, 0}, {0, 1, 0}, {1, 1, 1}
};
int *table[MAX_NO + 1];

// table[1][1] == table_[0][0]
void create_table() {
    for(int i = 1; i <= MAX_NO; ++i) {
        table[i] = table_[i - 1] - 1;
    }
}

int lookup(int n, int m) {
    switch(n){
        case 1: case 2: case 3:
            return table[n][m];
    }

    if(table[n][m]) return table[n][m];

    for(int i = 1; i <= 3; ++i) {
        if (i == m) continue;
        table[n][m] += lookup(n - m, i);
    }
    table[n][m] %= DIVISOR;
    return table[n][m];
}

int main() {
    create_table();

    lookup(4,1);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        cout << (lookup(n,1) + lookup(n,2) + lookup(n,3)) % DIVISOR << '\n';
    }
    return 0;
}