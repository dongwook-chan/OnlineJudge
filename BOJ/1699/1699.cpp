/*
    제곱수 나열: 1, 4, 9, ...
    1 4개보다는 4 1개가 최소항 -> 3까지는 1로 만들고, 4부터는 4로 만들어야
    Greedy하게 N보다 작으면서 가장 큰 제곱수부터 채워나가면 될 듯?

    단, 작은 수 부터 탐색(bottom-up)해나가야 '가장 큰 제곱수' 늘려나갈 수 있다.
    큰 수부터 탐색하면(top-down) '가장 큰 제곱수'를 이진 탐색으로 찾아야 한다.

    위 가정이 틀림...
    n에 대해서 n^(1/2)개의 '제곱수'를 모두 고려해야 
*/

#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_SIZE 100000
#define NOT_MEMOIZED INT_MAX

using namespace std;

int table[MAX_SIZE];
void init_table() {
    fill(table, table + MAX_SIZE + 1, NOT_MEMOIZED);
}

int lookup(int n) {
    if(n == 0) return 0;

    // memoized
    if(table[n] != NOT_MEMOIZED) return table[n];

    // not memoized
    for(int i = 1, s = 1; s <= n; ++i, s = i * i){
        table[n] = min(table[n], lookup(n - s) + 1);
    }
    return table[n];
}

int main() {
    init_table();

    int N;
    cin >> N;

    cout << lookup(N);

    //for(int i = 1; i <= N; ++i) cout << table[i] << ' ';

    return 0;
}