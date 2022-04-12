#include <iostream>
#include <set>

using namespace std;

int n;
int prev_y;
set<int> ys;
int bldg_ctr;

int main() {
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;

        ys.insert(y);

        if(y < prev_y) {
            for(;ys.size() && *ys.begin() > y; ys.erase(ys.begin())) {
                cout << n << ": " << x <<", " <<y << endl;
                ++bldg_ctr;
            }
        }

        prev_y = y;
    }
    cout << bldg_ctr;

    return 0;
}