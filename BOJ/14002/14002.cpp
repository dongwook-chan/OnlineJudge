#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX_SIZE 1000
#define NOT_MEMOIZED -1

using namespace std;

unsigned int table[MAX_SIZE + 1];
unsigned int A[MAX_SIZE + 1];
unsigned int parent[MAX_SIZE + 1];

void init_table() {
    memset(table, NOT_MEMOIZED, sizeof(table));
}

unsigned int lookup(int n) {
    // memoized
    if(table[n] != NOT_MEMOIZED) return table[n];

    // not memoized
    table[n] = 1;
    for(int i = 1; i < n; ++i){
        if(A[n] > A[i] && table[n] < lookup(i) + 1) {
            table[n] = table[i] + 1;
            parent[n] = i;
        }
    }
    return table[n];
}

int main() {
    init_table();

    int N;
    cin >> N;
    
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for(int i = 1; i <= N; ++i) {
        lookup(i);
    }

    unsigned int *max_p = max_element(table + 1, table + N + 1);
    cout << *max_p << '\n';

    int max_i = max_p - table;
    vector<unsigned int> ans;
    for(int i = max_i; i >= 1; i = parent[i]){
        ans.push_back(A[i]);
    }

    reverse(ans.begin(), ans.end());
    for(unsigned int a : ans) {
        cout << a << ' ';
    }

    return 0;
}