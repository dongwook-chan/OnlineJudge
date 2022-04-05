/*
# 최초 점화식
f(1, n) = max(f(1, n - 1), f(2, n - 1), ..., f(n - 1, n - 1)) + I[n]
- 연속이어야 하기 때문에 2번째 인자가 n - 1이 아닌 경우를 생각할 필요가 없음

# 인자 줄이기
- 최초 점화식의 인자들이 상당히 단조로운 패턴을 보여주기에, 인자 줄이기 시도
g(n) = f(1, n)
g(n) = max(g(n - 1), g(n - 1) - g(1), ..., g(n - 1) - g(n - 2)) + I[n]
- 위 점화식의 시간복잡도는 n^2라 입력의 크기가 100,000인 본 문제에 부적합

# 규칙 찾기
첫번째 음수 f(1, 1)은 무조건 버려도 된다. 양수만 합의 증가에 도움이 되기 때문
연속이라는 조건 때문에 특정 수를 버리면 그 수와 이전 수들은 합에 사용할 수 없게 된다.

양수이다가 처음으로 음수가 된 leading subsequence f(1, n)도 버려도 된다.
I[n] < 0이고, |I[n]| > f(1, n - 1)이기 때문에
f(1, n - 1), f(2, n - 1), ..., f(n - 1, n - 1) 중 그 어떤 것도 양수가 될 수 없기 때문

버리고 난 뒤 합은 0이 된다.
*/

#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_SIZE 100000
#define NOT_MEMOIZED INT_MAX

using namespace std;

int table[MAX_SIZE];
int I[MAX_SIZE];

void init_table() {
    fill(table, table + MAX_SIZE, NOT_MEMOIZED);
}

int replace_negative_with_zero(int n) {
    if(n < 0) return 0;
    else return n;
}

int lookup(int n) {
    // base case
    if(n < 0) return 0;

    // memoized
    if(table[n] != NOT_MEMOIZED) return table[n];

    // not memoized
    table[n] = replace_negative_with_zero(lookup(n - 1)) + I[n]; // n = 1인 경우

    return table[n];
}

int main() {
    init_table();

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> I[i];
    }

    lookup(n - 1);

    cout << *max_element(table, table + n); 

    return 0;
}