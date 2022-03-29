#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int memo[1000000];

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
