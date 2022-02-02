#include <iostream>
#include <cstring>

#define GRID_MAX_SIZE 50

using namespace std;

int N, M;
int A[GRID_MAX_SIZE + 1][GRID_MAX_SIZE + 1];
bool cloud[GRID_MAX_SIZE + 1][GRID_MAX_SIZE + 1];
bool new_cloud[GRID_MAX_SIZE + 1][GRID_MAX_SIZE + 1];
// X, ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int new_pos(int z, int dz) {
    return (N * 50 + z - 1 + dz) % N + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            cin >> A[y][x];
        }
    }

    // 비바라기를 시전하면 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생긴다.
    cloud[N][1] = cloud[N][2] = cloud[N - 1][1] = cloud[N - 1][2] = true;

    while (M--) {
        int d, s;
        cin >> d >> s;

        // 1. 모든 구름이 di 방향으로 si칸 이동한다.
        // 격자의 가장 왼쪽 윗 칸은 (1, 1)이고, 가장 오른쪽 아랫 칸은 (N, N)이다. 마법사 상어는 연습을 위해 1번 행과 N번 행을 연결했고, 1번 열과 N번 열도 연결했다. 즉, N번 행의 아래에는 1번 행이, 1번 행의 위에는 N번 행이 있고, 1번 열의 왼쪽에는 N번 열이, N번 열의 오른쪽에는 1번 열이 있다.
        memset(new_cloud, false, sizeof(new_cloud));
        for (int y = 1; y <= N; ++y) {
            for (int x = 1; x <= N; ++x) {
                if (!cloud[y][x]) continue;
                new_cloud[new_pos(y, dy[d] * s)][new_pos(x, dx[d] * s)] = true;
            }
        }
        memcpy(cloud, new_cloud, sizeof(new_cloud));

        // 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
        for (int y = 1; y <= N; ++y) {
            for (int x = 1; x <= N; ++x) {
                if (!cloud[y][x]) continue;
                ++A[y][x];
            }
        }

        // 3. 구름이 모두 사라진다.

        // 4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다. 
        // 이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
        for (int y = 1; y <= N; ++y) {
            for (int x = 1; x <= N; ++x) {
                if (!cloud[y][x]) continue;

                int ctr = 0;
                for (int d = 2; d <= 8; d += 2) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if (!(1 <= ny && ny <= N && 1 <= nx && nx <= N)) continue;
                    if (!A[ny][nx]) continue;

                    ++ctr;
                }

                A[y][x] += ctr;
            }
        }

        // 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
        memset(new_cloud, false, sizeof(new_cloud));
        for (int y = 1; y <= N; ++y) {
            for (int x = 1; x <= N; ++x) {
                if (A[y][x] < 2) continue;
                if (cloud[y][x]) continue;

                A[y][x] -= 2;
                new_cloud[y][x] = true;
            }
        }
        memcpy(cloud, new_cloud, sizeof(new_cloud));
    }

    int sum = 0;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            sum += A[y][x];
        }
    }

    cout << sum;
    return 0;
}