/*
# 예제 분석
## 1번
(0, 20), (1, 19), ..., (20, 0) = f(20, 1) * 2 + f(19, 2)
## 2번
(0, 0, 0, 6),
(0, 0, 1, 5),
...
(0, 0, 6, 0)

# 풀이법 일반화
## 1번 예제 기준
K 중 몇 자리를 사용할지 선택 (선택되지 않은 자리는 0)
### 1자리만 사용
(0, 20), (20, 0) -> f(20, 1) * 2
### 2자리만 사용
(1, 19), (2, 18), ..., (19, 1) -> f(18, 2)

## 2번 예제 기준
K 중 몇 자리를 사용할지 선택 (선택되지 않은 자리는 0)
### 1자리만 사용
(0, 0, 0, 6), (0, 0, 6, 0), (0, 6, 0, 0), (6, 0, 0, 0) -> f(6, 1) * c(4, 1)

### 2자리만 사용
(0, 0, 1, 5), ..., (0, 0, 5, 1) == (0, 4), ..., (4, 0)
(0, 1, 0, 5), ..., 
...
-> f(4, 2) * c(4, 2)

### 3자리만 사용
(0, 1, 1, 4), ..., 
...
-> f(3, 3) * c(4, 3)

### 4자리만 사용
(1, 1, 1, 3), ..., 
...
-> f(2, 4) * c(4, 4)

## f(2, 4) ???
#### 1자리만  사용
f(2, 1) * c(4, 1)
#### 2자리만 사용
f(0, 2) * c(4, 2) -> n == 0일 경우 f(n, k) = 1

# c(n, k): 파스칼의 삼각형 
c(1, 0): 1  c(1, 1): 1
c(2, 0): 1  c(2, 1): 2  c(2, 2): 1
c(3, 0): 1  c(3, 1): 3  c(3, 2): 3  c(3, 3): 1
...
*/

#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_NO 200
#define NOT_MEMOIZED INT_MAX
#define DIVISOR 1000000000

using namespace std;

int table[MAX_NO + 1][MAX_NO + 1];
int combination[MAX_NO + 1][MAX_NO + 1];

void init_array(int array[MAX_NO + 1][MAX_NO + 1]) {
    for(int i = 0; i <= MAX_NO; ++i) {
        fill(array[i], array[i] + MAX_NO + 1, NOT_MEMOIZED);
    }
}

int lookup_combination(int n, int k) {
    // base case
    if(k == 0 || k == n) return 1;

    // memoized
    if(combination[n][k] != NOT_MEMOIZED) return combination[n][k];

    // not memoized
    combination[n][k] = lookup_combination(n - 1, k - 1) + lookup_combination(n - 1, k);
    combination[n][k] %= DIVISOR;
    return combination[n][k];
}

int lookup_table(int n, int k) {
    // base case 
    if(n == 0 || k == 1) return 1;

    // memoized
    if(table[n][k] != NOT_MEMOIZED) return table[n][k];

    // not memoized
    table[n][k] = 0;
    for(int i = 1; i <= min(n, k); ++i) {   // NOTE: 아래 식의 n - i이 음수가 되면 안 됨
        table[n][k] += ((long long)lookup_table(n - i, i) * lookup_combination(k, i)) % DIVISOR;
        table[n][k] %= DIVISOR;
    }
    return table[n][k];
}

int main() {
    init_array(table);
    init_array(combination);

    int N, K;
    cin >> N >> K;
    //N = 200, K = 200;

    cout << lookup_table(N, K);

    return 0;
}
