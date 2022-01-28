#include <iostream>
#include <deque>

using namespace std;

struct stat {
    int m, s, d, r;
};

int grid_size_max, fireball_ctr_max, round_max;
deque<stat> fireballs[51][51];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> grid_size_max >> fireball_ctr_max >> round_max;
    for (int fireball_ctr = 0; fireball_ctr < fireball_ctr_max; ++fireball_ctr) {
        int r, c, m, s, d;
        cin >> r >> c;
        stat fireball;
        cin >> fireball.m >> fireball.s >> fireball.d;
        fireball.r = 0;
        fireballs[r][c].push_back(fireball);
    }

    for (int round = 1; round <= round_max; ++round) {
        // 1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다. 
        for (int r = 1; r <= grid_size_max; ++r) {
            for (int c = 1; c <= grid_size_max; ++c) {
                deque<stat> &q = fireballs[r][c];
                int qs = q.size();
                while(qs--) {
                    stat fireball = q.front();
                    if (fireball.r == round) break;     // 이번 round에 추가된 fireball을 발견하면 "pop하지 않고" 넘어간다.

                    q.pop_front();

                    int nr = (1000 * grid_size_max + (r - 1) + dr[fireball.d] * fireball.s) % grid_size_max + 1;       // d가 음수인 경우도 생각해야!
                    int nc = (1000 * grid_size_max + (c - 1) + dc[fireball.d] * fireball.s) % grid_size_max + 1;
                    fireball.r = round;

                    fireballs[nr][nc].push_back(fireball);
                }
            }
        }
        // 2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다. 
        for (int r = 1; r <= grid_size_max; ++r) {
            for (int c = 1; c <= grid_size_max; ++c) {
                int qs = fireballs[r][c].size();
                if (qs < 2) continue;

                int sum_m = 0;
                int sum_s = 0;
                bool parity = fireballs[r][c][0].d % 2;
                bool is_parity_consistent = true;
                for (auto fireball : fireballs[r][c]) {
                    sum_m += fireball.m;
                    sum_s += fireball.s;
                    if (fireball.d % 2 != parity) {
                        is_parity_consistent = false;
                    }
                }
                fireballs[r][c].clear();

                if (sum_m / 5 == 0) continue;

                for (int i = 0; i < 4; ++i) {
                    stat fireball;
                    fireball.m = sum_m / 5;
                    fireball.s = sum_s / qs;
                    fireball.d = i * 2 + !is_parity_consistent;
                    fireball.r = round;
                    fireballs[r][c].push_back(fireball);
                }
            }
        }
    }

    int sum_m = 0;
    for (int r = 1; r <= grid_size_max; ++r) {
        for (int c = 1; c <= grid_size_max; ++c) {
            for (auto fireball : fireballs[r][c]) {
                sum_m += fireball.m;
            }
        }
    }

    cout << sum_m;

    return 0;
}