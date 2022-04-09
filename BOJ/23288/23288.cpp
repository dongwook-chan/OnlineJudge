#include <iostream>
#include <cstring>

#define MAX_SIZE 20
#define OOM(r, c) (!(1 <= (r) && (r) <= N && 1 <= (c) && (c) <= M))     // Out Of Map

using namespace std;

enum DIRECTION {EAST, SOUTH, WEST, NORTH};

int N, M, K;
int map[MAX_SIZE + 1][MAX_SIZE + 1];

int r = 1, c = 1;  // 놓여져 있는 곳의 좌표는 (1, 1) 이다. 
DIRECTION dir = EAST;    // 가장 처음에 주사위의 이동 방향은 동쪽이다.
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int dice[6] = {2, 4, 1, 3, 5, 6};  // 주사위는 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있으며
int new_dice[6];
int new_plane_after_rotate[4][6] = {
    // EAST
    {0, 5, 1, 2, 4, 3},
    // SOUTH
    {5, 1, 0, 3, 2, 4},
    // WEST
    {0, 2, 3, 5, 4, 1},
    // NORTH
    {2, 1, 4, 3, 5, 0}
};
int score;

bool visited[MAX_SIZE + 1][MAX_SIZE + 1];
int visited_tiles;
// (x, y)에 있는 정수를 B라고 했을때, (x, y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수 C를 모두 구한다.
void dfs(int r, int c) {
    visited[r][c] = true;
    ++visited_tiles;
    
    for(int dir = 0; dir < 4; ++dir) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if(OOM(nr, nc)) continue;
        if(map[nr][nc] != map[r][c]) continue;  // 이때 이동할 수 있는 칸에는 모두 정수 B가 있어야 한다. 
        if(visited[nr][nc]) continue;

        dfs(nr, nc);
    }
}

int main() {
    cin >> N >> M >> K;
    for(int r_map = 1; r_map <= N; ++r_map) {
        for(int c_map = 1; c_map <= M; ++c_map) {
            cin >> map[r_map][c_map];
        }
    }

    // 주사위의 이동 한 번은 다음과 같은 방식으로 이루어진다.
    while(K--) {
        // 1. 주사위가 이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        if(OOM(nr, nc)) {
            dir = (DIRECTION) ((dir + 2) % 4);

            nr = r + dr[dir];
            nc = c + dc[dir];
        }

        r = nr;
        c = nc;

        for(int p = 0; p < 6; ++p) {
            new_dice[p] = dice[new_plane_after_rotate[dir][p]];
        }
        memcpy(dice, new_dice, sizeof(new_dice));

        // 2. 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
        // 칸 (x, y)에 대한 점수는 다음과 같이 구할 수 있다. 
        memset(visited, false, sizeof(visited));
        visited_tiles = 0;
        dfs(r, c);
        score += map[r][c] * visited_tiles;

        // 3. 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
        int A = dice[5];
        int B = map[r][c];
        // A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
        if(A > B) {
            dir = (DIRECTION) ((dir + 1) % 4);
        }
        // A < B인 경우 이동 방향을 90도 반시계 방향으로 회전시킨다.
        else if(A < B) {
            dir = (DIRECTION) ((dir + 3) % 4);
        }
        // A = B인 경우 이동 방향에 변화는 없다.
    }

    cout << score;

    return 0;
}