#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

#define MAX_GRID 4
#define MAX_FISH 10
#define MAX_REP 100
#define OOG(r, c) (!(1 <= (r) && (r) <= 4 && 1 <= (c) && (c) <= 4))  // Out Of Grid
//#define DEBUG

using namespace std;

// 방향은 8 이하의 자연수로 표현하고, 1부터 순서대로 ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 이다.
enum DIRECTION {NONE, LEFT, LU, UP, UR, RIGHT, RD, DOWN, DL};

int M, S;
vector<int> fish[MAX_GRID + 1][MAX_GRID + 1];
bool shark[MAX_GRID + 1][MAX_GRID + 1];

// #1
vector<int> fish_replicated[MAX_GRID + 1][MAX_GRID + 1];
void copy_grid(vector<int> dst[MAX_GRID + 1][MAX_GRID + 1], vector<int> src[MAX_GRID + 1][MAX_GRID + 1]) {
    for(int r = 1; r <= 4; ++r) {
        for(int c = 1; c <= 4; ++c) {
            dst[r][c] = src[r][c];
        }
    }
}

// #2
int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
bool fish_smell[MAX_GRID + 1][MAX_GRID + 1][MAX_REP + 2];
bool check_fish_smell(int r, int c, int s) {
    for(int ns = s; ns < MAX_REP && ns < s + 2; ++ns) {
        if(fish_smell[r][c][ns]) return true;
    }
    return false;
}
vector<int> fish_traveled[MAX_GRID + 1][MAX_GRID + 1];

// #3
int dir_trace[3];
int max_fish_ctr;
int min_dir_trace[3];
// 상은 1, 좌는 2, 하는 3, 우는 4로 변환한다.
vector<int> prioritized_dir = {UP, LEFT, DOWN, RIGHT};
void shark_travel(int r, int c, int move_ctr, int fish_ctr) {
    //visited[r][c] = true; // NOTE: 지나온 칸도 재방문 가능
    vector<int> fish_tmp;
    if(move_ctr) {  // NOTE: 이동 전에 최초 위치에 있는 물고기는 못 먹음
        fish_ctr += fish[r][c].size();  // 연속해서 이동하는 중에 상어가 물고기가 있는 같은 칸으로 이동하게 된다면, 
        fish_tmp = fish[r][c];
        fish[r][c].clear();
    }

    if(move_ctr >= 3) {
        if(fish_ctr > max_fish_ctr) {    // 가능한 이동 방법 중에서 제외되는 물고기의 수가 가장 많은 방법으로 이동하며, 그러한 방법이 여러가지인 경우 사전 순으로 가장 앞서는 방법을 이용한다.
            max_fish_ctr = fish_ctr;
            memcpy(min_dir_trace, dir_trace, sizeof(dir_trace));
        }
        goto undo_visit;   // NOTE: return해버리면 undo visit이 안 됨...
    } 

    for(int dir : prioritized_dir) {    // 상어는 현재 칸에서 상하좌우로 인접한 칸으로 이동할 수 있다. 
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if(OOG(nr, nc)) continue;   // 연속해서 이동하는 칸 중에 격자의 범위를 벗어나는 칸이 있으면, 그 방법은 불가능한 이동 방법이다.

        dir_trace[move_ctr] = dir;

        shark_travel(nr, nc, move_ctr + 1, fish_ctr);
    }

undo_visit:
    if(move_ctr) {
        fish[r][c] = fish_tmp;
    }
}

int main() {
    cin >> M >> S;
    for(int m = 0; m < M; ++m) {
        int fx, fy, d;
        cin >> fx >> fy >> d;
        fish[fx][fy].push_back(d);
    }
    int sx, sy;
    cin >> sx >> sy;
    shark[sx][sy] = true;

    // 상어의 마법 연습 한 번은 다음과 같은 작업이 순차적으로 이루어진다.
    for(int s = 0; s < S; ++s) {
#ifdef DEBUG
        cout << "s: " << s << endl;
#endif
        // #1 상어가 모든 물고기에게 복제 마법을 시전한다. 복제 마법은 시간이 조금 걸리기 때문에, 아래 5번에서 물고기가 복제되어 칸에 나타난다.
        copy_grid(fish_replicated, fish);

        // #2 모든 물고기가 한 칸 이동한다.
        for(int r = 1; r <= 4; ++r) {
            for(int c = 1; c <= 4; ++c) {
                fish_traveled[r][c].clear();
            }
        }
        for(int r = 1; r <= 4; ++r) {
            for(int c = 1; c <= 4; ++c) {
                for(int d : fish[r][c]) {
                    int nd = d;
                    for(int _ = 0; _ < 8; ++_) {
                        int nr = r + dr[nd];
                        int nc = c + dc[nd];

                        if(OOG(nr, nc)) goto next_direction;   // 격자의 범위를 벗어나는 칸으로는 이동할 수 없다.
                        if(shark[nr][nc] || check_fish_smell(nr, nc, s)) goto next_direction;   // 상어가 있는 칸, 물고기의 냄새가 있는 칸

                        fish_traveled[nr][nc].push_back(nd); // 그 외의 경우에는 그 칸으로 이동을 한다.
                        //cout << nd << endl;
                        goto next_fish;
                        
                    next_direction:
                        nd = ((nd - 1) + 7) % 8 + 1; // 각 물고기는 자신이 가지고 있는 이동 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전시킨다.
                    }
                    // 만약, 이동할 수 있는 칸이 없으면 이동을 하지 않는다.
                    fish_traveled[r][c].push_back(d);   // note: 이동하지 않고 제자리인 경우에도 fish_traveld에 추가해줘야
                next_fish:
                    continue;
                }
            }
        }
        copy_grid(fish, fish_traveled);

        // #3 상어가 연속해서 3칸 이동한다.
        for(int r = 1; r <= 4; ++r) {
            for(int c = 1; c <= 4; ++c) {
                if(!shark[r][c]) continue;

                //cout << r << ", " << c << endl;

                //memset(visited, false, sizeof(visited));
                max_fish_ctr = -1;
                shark_travel(r, c, 0, 0);

                int nr = r, nc = c;
                for(int i = 0; i < 3; ++i) {
                    int dir = min_dir_trace[i];

                    nr += dr[dir];
                    nc += dc[dir];

                    if(fish[nr][nc].size()) {
                        fish[nr][nc].clear();   // 그 칸에 있는 모든 물고기는 격자에서 제외되며,
                        fish_smell[nr][nc][s + 2] = true; // 제외되는 모든 물고기는 물고기 냄새를 남긴다. 
                    }
                }
                shark[r][c] = false;
                shark[nr][nc] = true;
                goto end_shark_travel;
            }
        }
    end_shark_travel:
        ;

        // #4 두 번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라진다.
        for(int r = 1; r <= 4; ++r) {
            for(int c = 1; c <= 4; ++c) {
                fish_smell[r][c][s] = false;
            }
        }

        // 5. 1에서 사용한 복제 마법이 완료된다. 모든 복제된 물고기는 1에서의 위치와 방향을 그대로 갖게 된다.
        for(int r = 1; r <= 4; ++r) {
            for(int c = 1; c <= 4; ++c) {
                if(fish_replicated[r][c].empty()) continue;
                fish[r][c].insert(fish[r][c].end(), fish_replicated[r][c].begin(), fish_replicated[r][c].end());
            }
        }
    }

    int fish_ctr = 0;
    for(int r = 1; r <= 4; ++r) {
        for(int c = 1; c <= 4; ++c) {
            fish_ctr += fish[r][c].size();
        }
    }

    cout << fish_ctr;

    return 0;
}