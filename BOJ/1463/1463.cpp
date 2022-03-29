// Memoization(Top-Down)
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX_NO 1000000

using namespace std;

unsigned int memo[MAX_NO + 1];

unsigned int lookup(unsigned int N) {
    if(N == 1){
        return 0;
    }
    if(memo[N] != -1){
        return memo[N];
    }

    if(N % 3 == 0){
        memo[N] = min(memo[N], lookup(N / 3) + 1);
    }
    if(N % 2 == 0){
        memo[N] = min(memo[N], lookup(N / 2) + 1);
    }
    memo[N] = min(memo[N], lookup(N - 1) + 1);

    return memo[N];
}

int main(){
    memset(memo, -1, sizeof(memo));

    unsigned int N;
    cin >> N;

    cout << lookup(N);

    return 0;
}

/*
// Tabulation(Bottom-Up)
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX_NO 1000000

using namespace std;

unsigned int memo[MAX_NO + 1];

int main() {
    memset(memo, -1, sizeof(memo));

    int N;
    cin >> N;
    
    memo[1] = 0;
    memo[2] = 1;
    for(int i = 3; i <= N; ++i) {
        if(i % 3 == 0) {
            memo[i] = min(memo[i], memo[i / 3] + 1);
        }
        if(i % 2 == 0) {
            memo[i] = min(memo[i], memo[i / 2] + 1);
        }
        memo[i] = min(memo[i], memo[i - 1] + 1);
    }

    cout << memo[N];
    return 0;
}
*/