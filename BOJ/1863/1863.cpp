#include <iostream>
#include <queue>

using namespace std;

int n;
int prev_y;
priority_queue<int> pq;
int bldg_ctr;

int main() {
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;

        pq.push(y);

        if(y < prev_y) {
            for(;pq.size() && pq.top() > y; pq.pop()) ++bldg_ctr;
        }

        prev_y = y;
    }
    cout << bldg_ctr;

    return 0;
}