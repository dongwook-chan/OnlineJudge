#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
bool err_dgt[10];
vector<int> dgts;
int chl_len;
int answer;

void bf(int pos, int chl){
    if (pos) {
        answer = min(answer, pos + abs(N - chl));
    }
    
    if (pos > chl_len) return;

    for (int dgt : dgts) {
        bf(pos + 1, chl * 10 + dgt);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
        greedily select digit buttons first then up/down buttons
            case 1) 100 (no digit selection) -> up/down buttons
            case 2) digit selections -> up/down buttons
    */

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int dgt;
        cin >> dgt;
        err_dgt[dgt] = true;
    }

    for (int dgt = 0; dgt < 10; ++dgt) {
        if (err_dgt[dgt]) continue;
        dgts.push_back(dgt);
    }

    answer = abs(N - 100);

    chl_len = to_string(N).size();
    bf(0, 0);

    cout << answer;

    return 0;
}