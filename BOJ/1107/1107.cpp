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

void bf(int pos, int chl, int chl_len){
    if (pos == chl_len) {
        answer = min(answer, pos + abs(N - chl)); // 하나도 선택되지 않았을 때의 거리는 abs(N - 100), 본 거리 공식은 적어도 한 개가 선택됐을 경우에만 적용됨
        return;
    }

    for (int dgt : dgts) {
        bf(pos + 1, chl * 10 + dgt, chl_len);
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

    answer = abs(N - 100);  // '거리'를 구하는 것이므로 abs 사용

    chl_len = to_string(N).size();
    int tgt_MSD = to_string(N)[0] - '0';

    if (!err_dgt[tgt_MSD]) {
        bf(1, tgt_MSD, chl_len);
    }

    int MSD;
    for (MSD = tgt_MSD - 1; MSD >= 0; --MSD) {
        if (!err_dgt[MSD]) break;
    }
    if (MSD >= 0) {
        bf(1, MSD, chl_len);
    }

    for (MSD = tgt_MSD + 1; MSD < 10; ++MSD) {
        if (!err_dgt[MSD]) break;
    }
    if (MSD < 10) {
        bf(1, MSD, chl_len);
    }
    
    if (dgts.size()) {
        bf(1, *min_element(dgts.begin(), dgts.end()), chl_len + 1);
    }

    if (dgts.size() && chl_len > 1) {
        bf(1, *max_element(dgts.begin(), dgts.end()), chl_len - 1);
    }


    cout << answer;

    return 0;
}