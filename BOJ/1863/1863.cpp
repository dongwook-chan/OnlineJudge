#include <iostream>
#include <functional>
#include <set>

#define MAX_SEQUENCE_SIZE 50000

using namespace std;

int n;
int y_sequence[MAX_SEQUENCE_SIZE + 1];
int prev_y;
set<int, greater<int>> y_subsequence;
int bldg_ctr;

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x >> y_sequence[i];
    }
    y_sequence[n] = 0;

    for(int i = 0; i < n; ++i) {
        int y = y_sequence[i];
        
        y_subsequence.insert(y);

        if(y < prev_y) {
            for(;y_subsequence.size() && *y_subsequence.begin() > y; y_subsequence.erase(y_subsequence.begin())) {
                ++bldg_ctr;
            }
        }
        prev_y = y;
    }
    cout << bldg_ctr;

    return 0;
}