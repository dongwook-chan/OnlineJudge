#include <iostream>
#include <climits>
#include <algorithm>
#include <string>

#define MAX_SIZE 16
#define NOT_MEMOIZED INT_MAX

using namespace std;

int N;
int cost[MAX_SIZE][MAX_SIZE];
string plant_status_;
int P, P_;
int min_cost_for_bm[1 << MAX_SIZE];
int min_cost_for_cnt[MAX_SIZE];
int plant_status;

void init_table() {
    fill(min_cost_for_bm, min_cost_for_bm + (1 << MAX_SIZE), NOT_MEMOIZED);
    fill(min_cost_for_cnt, min_cost_for_cnt + MAX_SIZE, INT_MAX);
}

int lookup(int n, int cnt) {
    // base case
    if(n == plant_status) return 0;

    // memoized
    if(min_cost_for_bm[n] != NOT_MEMOIZED) return min_cost_for_bm[n];

    // not memoized
    for(int j = 0; j < N; ++j) {
        int bj = 1 << j;
        if((plant_status & bj) == bj) continue;
        if((n & bj) != bj) continue;
        int new_n = n ^ bj;

        for(int i = 0; i < N; ++i) {
            int bi = 1 << i;
            if((new_n & bi) != bi) continue;
            min_cost_for_bm[n] = min(min_cost_for_bm[n], lookup(new_n, cnt - 1) + cost[i][j]);
            min_cost_for_cnt[cnt] = min(min_cost_for_cnt[cnt], min_cost_for_bm[n]);
        }
    }
    return min_cost_for_bm[n];
}

int main() {
    init_table();

    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
    }
    cin >> plant_status_;
    cin >> P;

    for(int i = 0; i < plant_status_.size(); ++i) {
        int b = 1 << i;
        if(plant_status_[i] == 'Y') {
            plant_status |= b; 
            ++P_;
        }
    }

    if(!P || P_ > P) {
        cout << 0;
        return 0;
    }
    if(!P_) {
        cout << -1;
        return 0;
    }
    
    lookup(((1 << N) - 1), N);

    cout << min_cost_for_cnt[P];

    return 0;
}