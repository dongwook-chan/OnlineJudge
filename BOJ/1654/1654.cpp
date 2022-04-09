#include <iostream>
#include <queue>
#include <functional>
#include <vector>

#define MAX_LAN_CNT 10000

using namespace std;

int K, N;
int lan_len[MAX_LAN_CNT];
int lan_divided[MAX_LAN_CNT];
int tot_lan_divided;
int max_threshold;

struct idx_threshold {
    int idx, threshold;
};
struct compare {
    bool operator() (const idx_threshold &a, const idx_threshold &b) {
        return a.threshold < b.threshold;
    }
};
priority_queue<idx_threshold, vector<idx_threshold>, compare> pq;

int main() {
    cin >> K >> N;

    for(int i = 0; i < K; ++i) {
        cin >> lan_len[i];
        pq.push({i, lan_len[i]});
    }

    while(pq.size()) {
        idx_threshold cur_lan = pq.top();
        pq.pop();

        int cur_idx = cur_lan.idx;
        int cur_threshold = cur_lan.threshold;

        ++lan_divided[cur_idx];
        ++tot_lan_divided;

        if(tot_lan_divided >= N) {
            max_threshold = cur_threshold;
            break;
        }

        pq.push({cur_idx, lan_len[cur_idx] / (lan_divided[cur_idx] + 1)});
    }

    cout << max_threshold;

    return 0;
}
