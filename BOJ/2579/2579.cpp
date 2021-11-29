#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int str_ctr;
int strs[300];
int cached[300];

int df (int idx) {
    switch (idx) {
        case 1:
            return strs[1];
        case 2:
            return strs[0] + strs[2]; 
        case 3:
            return strs[0] + strs[1] + strs[3];
    }
    if (cached[idx]) {
        return cached[idx];
    }
    if (idx >= 3) {
        cached[idx] = max(cached[idx], df(idx - 2) + strs[idx]);
    }
    if (idx >= 4) {
        cached[idx] = max(cached[idx], df(idx - 3) + strs[idx - 2] + strs[idx]);
    }
    return cached[idx];
}

int main() {
    cin >> str_ctr;

    for (int i = 0; i < str_ctr; ++i) {
        cin >> strs[i];
    }

    cout << df (str_ctr - 1);
    
    return 0;
}