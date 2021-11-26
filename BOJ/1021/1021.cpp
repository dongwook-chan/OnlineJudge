#include <iostream>
#include <deque>
#include <numeric>
#include <algorithm>

using namespace std;

int N, M;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    deque<int> dq(N);
    iota(dq.begin(), dq.end(), 1);

    while (M--) {
        int pick;
        cin >> pick;

        int pick_idx = find(dq.begin(), dq.end(), pick) - dq.begin();
        //cout << pick << ": " << pick_idx << endl;

        if (pick_idx < dq.size() - pick_idx) {
            int rep = pick_idx;
            ans += rep;

            while(rep--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            int rep = dq.size() - pick_idx;
            ans += rep;

            while(rep--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
    }

    cout << ans;
    return 0;
}