#include <iostream>
#include <algorithm>
#include <cstring>

//#define DEBUG

using namespace std;

enum TYPE {EMPTY = -2, BLACK, RAINBOW, REGULAR};

int N, M;
int grid[20][20];
int tmp_grid[20][20];
bool visited[20][20];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int score;

// 블록 그룹은 연결된 블록의 집합이다. (O)
// 그룹에는 일반 블록이 적어도 하나 있어야 하며, 일반 블록의 색은 모두 같아야 한다. (O)
// 그룹에 속한 블록의 개수는 2보다 크거나 같아야 하며, (O)
// 임의의 한 블록에서 그룹에 속한 인접한 칸으로 이동해서 그룹에 속한 다른 모든 칸으로 이동할 수 있어야 한다. (O)
// 그룹의 기준 블록은 무지개 블록이 아닌 블록 중에서 행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이다. (O)
int block_color;
int block_size, max_block_size;
int rainbow_ctr, max_rainbow_ctr;
pair<int, int> base, max_base;

void find_block(int y, int x) {
    if (grid[y][x] != RAINBOW) {    // 그룹의 기준 블록은 무지개 블록이 아닌 블록 중에서
        base = min(base, {y, x});   //      행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이다.
    }
    else if (grid[y][x] == RAINBOW) {
        ++rainbow_ctr;
    }
    ++block_size;
}

void erase_block(int y, int x) {
    grid[y][x] = EMPTY;
}

void dfs(int y, int x, void (*do_for_pos)(int, int)) {
    visited[y][x] = true;
    if (grid[y][x] >= REGULAR && !block_color) block_color = grid[y][x];

    do_for_pos(y, x);
    
    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (!(0 <= ny && ny < N && 0 <= nx && nx < N)) continue;
        if (visited[ny][nx]) continue;
        if (grid[ny][nx] == EMPTY) continue;    // (블록이어야 한다.)
        if (grid[ny][nx] == BLACK) continue;    // 검은색 블록은 포함되면 안 되고,
        if (grid[ny][nx] >= REGULAR && grid[ny][nx] != block_color) continue;   // 일반 블록의 색은 모두 같아야 한다. 
        // FIXME: 자문의 1st iteration 해설과 나의 코드 비교하기: 해설에서는 색깔이 다르면 방문 X <-> 나는 색깔이 달라도 방문 O, 단지 블록으로 치지 않을 뿐... 

        dfs(ny, nx, do_for_pos);
    }
}

void pull() {
    for (int x = 0; x < N; ++x) {
        int y_land = N - 1;
        while (true) {
            // find lowest EMPTY tile
            for (; y_land >= 1 && grid[y_land][x] != EMPTY; --y_land);
            if (y_land <= 0) break;

            // find longest consecutive EMPTY tile
            int y_drop = y_land - 1;
            for (; y_drop >= 0 && grid[y_drop][x] == EMPTY; --y_drop);
            if (y_drop < 0) break;
            
            if (grid[y_drop][x] == BLACK) {
                y_land = y_drop - 1;
                continue;
            }
            
            swap(grid[y_land][x], grid[y_drop][x]);
            --y_land;
        }
    end:
        continue;
    }
}

void print() {
    static int i = 0;
#ifdef DEBUG
    cout << ++i << "th step\n";
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << ((grid[y][x] < 0) ? "" : " ") << grid[y][x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
#endif
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> grid[y][x];
        }
    }

    while(true) {
        // 1. 크기가 가장 큰 블록 그룹을 찾는다. 그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹, 그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을, 그 것도 여러개이면 열이 가장 큰 것을 찾는다.
        memset(visited, 0, sizeof(visited));
        max_block_size = 0;
        max_rainbow_ctr = 0;
        max_base = {-1, -1};
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (visited[y][x]) continue;
                if (grid[y][x] == BLACK) continue;     
                if (grid[y][x] == EMPTY) continue;       

                block_color = 0;
                block_size = 0;
                rainbow_ctr = 0;
                base = {N, N};
                dfs(y, x, find_block);

                if (!block_color) continue;                 // 그룹에는 일반 블록이 적어도 하나 있어야 하며,
                if (block_size < 2) continue;               // 그룹에 속한 블록의 개수는 2보다 크거나 같아야 하며,

                if (max_block_size < block_size) {          // 크기가 가장 큰 블록 그룹을 찾는다
                    max_block_size = block_size;
                    max_rainbow_ctr = rainbow_ctr;
                    max_base = base;
                }
                else if (max_block_size == block_size) {    // 그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹,
                    if (max_rainbow_ctr < rainbow_ctr) {
                        max_rainbow_ctr = rainbow_ctr;
                        max_base = base;
                    }
                    else if (max_rainbow_ctr == rainbow_ctr) {  // 그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을, 그 것도 여러개이면 열이 가장 큰 것을 찾는다.
                        max_base = max(max_base, base);
                    }
                } 
            }
        }
        if (max_block_size == 0) break;

#ifdef DEBUG
        cout << max_block_size << endl;
        cout << max_base.first << " " << max_base.second <<  endl;
#endif
        print();


        // 2. 1에서 찾은 블록 그룹의 모든 블록을 제거한다. 블록 그룹에 포함된 블록의 수를 B라고 했을 때, B2점을 획득한다.
        memset(visited, 0, sizeof(visited));
        block_color = 0;        // FIXME: dfs(erase_block) 호출 전에 dfs(find_block)과 마찬가지로 사전준비(자료구조 초기화) 필요
        dfs(max_base.first, max_base.second, erase_block);
        score += max_block_size * max_block_size;
        print();

        // 3. 격자에 중력이 작용한다.
        pull();
        print();

        // 4. 격자가 90도 반시계 방향으로 회전한다.
        memcpy(tmp_grid, grid, sizeof(grid));
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                grid[y][x] = tmp_grid[x][N - 1 - y];
            }
        }
        print();

        // 5. 다시 격자에 중력이 작용한다.
        pull();
        print();

#ifdef DEBUG
        return 0;
#endif
    }

    cout << score;

    return 0;
}