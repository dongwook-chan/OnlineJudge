#include <iostream>
#include <vector>
#include <algorithm>

//#define DEBUG

using namespace std;

int N;
int seat[21][21];
bool pref[21][401];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
struct info {
    int pref_ctr, empty_ctr, y, x;
};
int score_for_ctr[] = {0, 1, 10, 100, 1000};
int score;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int _ = 0; _ < N * N; ++_) {
        int stu_no;
        cin >> stu_no;
#ifdef DEBUG
        cout << stu_no << ": ";
#endif
        for (int __ = 0; __ < 4; ++__) {
            int pref_stu_no;
            cin >> pref_stu_no;
            pref[stu_no][pref_stu_no] = true;
        }

        vector<info> seat_rank;   
        for (int y = 1; y <= N; ++y) {
            for (int x = 1; x <= N; ++x) {
                if (seat[y][x]) continue;

                int pref_ctr = 0;
                int empty_ctr = 0;
                for (int d = 0; d < 4; ++d) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if (!(1 <= ny && ny <= N && 1 <= nx && nx <= N)) continue;

                    if (seat[ny][nx]) {
                        if (pref[stu_no][seat[ny][nx]]) ++pref_ctr;
                    }
                    else {
                        ++empty_ctr;
                    }
                }
                info seat = {pref_ctr, empty_ctr, y, x};
                seat_rank.push_back(seat);
            }
        }

        info chosen_seat = *max_element(seat_rank.begin(), seat_rank.end(), [](info &seat1, info &seat2) -> bool {
            if (seat1.pref_ctr == seat2.pref_ctr) {
                if (seat1.empty_ctr == seat2.empty_ctr) {
                    if (seat1.y == seat2.y) {
                        return seat1.x > seat2.x;
                    }
                    else return seat1.y > seat2.y;
                }
                else return seat1.empty_ctr < seat2.empty_ctr;
            }
            else return seat1.pref_ctr < seat2.pref_ctr;
        });
#ifdef DEBUG
        cout << chosen_seat.y << ' ' << chosen_seat.x << endl;
#endif
        seat[chosen_seat.y][chosen_seat.x] = stu_no;
    }

    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            int pref_ctr = 0;
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (!(1 <= ny && ny <= N && 1 <= nx && nx <= N)) continue;

                if (pref[seat[y][x]][seat[ny][nx]]) ++pref_ctr;
            }

            score += score_for_ctr[pref_ctr];
        }
    }

    cout << score;

    return 0;
}