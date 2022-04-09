#include <iostream>
#include <algorithm>
#include <functional>

#define MAX_SIZE 1000000

using namespace std;

int N, M;
int tree[MAX_SIZE];

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> tree[i];
    }

    sort(tree, tree + N, greater<int>());

    int log_len = 0;
    int i;
    for(i = 1; i < N; ++i) {
        int new_log_len = log_len + i * (tree[i - 1] - tree[i]);
        if(new_log_len > M) break;

        log_len = new_log_len;
    }
    int diff = M - log_len;
    cout << tree[i - 1] - (diff / i) - (diff % i != 0);

    return 0;
}