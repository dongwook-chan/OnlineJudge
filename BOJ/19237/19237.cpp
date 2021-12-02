#include <iostream>
#include <cstring>

//#define DEBUG

using namespace std;

int N, M, k;
int shark[20][20];
int priority[401][5][4];
int direction[401];
struct {
    int shark;
    int time;
} odor[20][20];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
struct point {
    int x;
    int y;
};

// @ d는 1부터 4까지, s는 1부터 M까지 -> out of array bound error 주의!
int main() {
    cin >> N >> M >> k;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            cin >> shark[x][y];
#ifdef DEBUG
            cout << shark[x][y] << '\t';
#endif
        }
#ifdef DEBUG
        cout << endl;
#endif
    }
#ifdef DEBUG
    cout << endl;
#endif

    for (int s = 1; s <= M; ++s) {
        cin >> direction[s];
    }

    for (int s = 1; s <= M; ++s) {
        for (int d = 1; d <= 4; ++d) {
            for (int p = 0; p < 4; ++p) {
                cin >> priority[s][d][p];
            }
        }
    }
    
    // 맨 처음에는 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (!shark[x][y]) continue;

            odor[x][y] = {shark[x][y], k};
        }
    }

    int t;
    for (t = 1; t <= 1000; ++t) {
        // "그 후 1초마다 모든 상어가 동시에 상하좌우로 인접한 칸 중 하나로 이동하고"
        /// "각 상어가 이동 방향을 결정할 때는, 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다. 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다. 이때 가능한 칸이 여러 개일 수 있는데, 그 경우에는 특정한 우선순위를 따른다. 우선순위는 상어마다 다를 수 있고, 같은 상어라도 현재 상어가 보고 있는 방향에 따라 또 다를 수 있다. 상어가 맨 처음에 보고 있는 방향은 입력으로 주어지고, 그 후에는 방금 이동한 방향이 보고 있는 방향이 된다."
        /// "모든 상어가 이동한 후 한 칸에 여러 마리의 상어가 남아 있으면, 가장 작은 번호를 가진 상어를 제외하고 모두 격자 밖으로 쫓겨난다."
        // @ x, y <-> nx, ny
        // @ x, y 순서
#ifdef DEBUG
        cout << "at " << t << " seconds\n";
#endif
        bool sharks[20][20][401] = {false};
        int dst_directions[20][20][401] = {0};
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (!shark[x][y]) continue;

                // 아무 냄새 없는 칸, 자신의 냄새가 있는 칸 탐색
                bool no_odor_directions[5] = {false};
                bool my_odor_directions[5] = {false};
                for (int d = 1; d <= 4; ++d) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;

                    if (!odor[nx][ny].shark) {
                        no_odor_directions[d] = true;
                    }
                    else if (odor[nx][ny].shark == shark[x][y]) {
                        my_odor_directions[d] = true;
                    }
                }

                int dst_direction = 0;
                for (int p = 0; p < 4; ++p) {
                    bool is_no_odor_direction = no_odor_directions[priority[shark[x][y]][direction[shark[x][y]]][p]];
                    if (!is_no_odor_direction) continue;
                    dst_direction = priority[shark[x][y]][direction[shark[x][y]]][p];
                    break;
                }
                if (!dst_direction) {
                    for (int p = 0; p < 4; ++p) {
                        bool is_prioritized_direction = my_odor_directions[priority[shark[x][y]][direction[shark[x][y]]][p]];
                        if (!is_prioritized_direction) continue;
                        dst_direction = priority[shark[x][y]][direction[shark[x][y]]][p];
                        break;
                    }
                }

#ifdef DEBUG
                cout << "destination direction for " << shark[x][y] << "th shark: " << dst_direction << "\n";
#endif
                int nx = x + dx[dst_direction];
                int ny = y + dy[dst_direction];
                sharks[nx][ny][shark[x][y]] = true;
                dst_directions[nx][ny][shark[x][y]] = dst_direction;
            }
        }

        memset (shark, 0, sizeof(shark));
        
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                // "모든 상어가 이동한 후 한 칸에 여러 마리의 상어가 남아 있으면, 가장 작은 번호를 가진 상어를 제외하고 모두 격자 밖으로 쫓겨난다."
                int s;
                for (s = 1; s <= M; ++s) {
                    if (sharks[x][y][s]) break;
                }
                if (s > M) continue;
                shark[x][y] = s;

                // "그 후에는 방금 이동한 방향이 보고 있는 방향이 된다."
                direction[shark[x][y]] = dst_directions[x][y][s];
            }
        }

        // 1번 상어만 격자에 남게 되기까지 몇 초가 걸리는지를 구하는 프로그램을 작성하시오.
        int shark_ctr = 0;
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
#ifdef DEBUG
                cout << shark[x][y] << '\t';
#endif
                if (!shark[x][y]) continue;
                ++shark_ctr;
            }
#ifdef DEBUG
                cout << endl;
#endif
        }
#ifdef DEBUG
        cout << endl;
#endif
        if (shark_ctr == 1) goto end;

        // "냄새는 상어가 k번 이동하고 나면 사라진다."
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                // 냄새가 존재하지 않으면 skip
                if (!odor[x][y].shark) continue;
                // 냄새 시간이 남아있다면 skip
                if (--odor[x][y].time) continue;

                odor[x][y].shark = 0;
                odor[x][y].time = 0;
            }
        }   

        // "자신의 냄새를 그 칸에 뿌린다."
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (!shark[x][y]) continue;

                odor[x][y] = {shark[x][y], k};
            }
        }
    }
    cout << -1;
    return 0;

end:
    cout << t;
    return 0;
}
