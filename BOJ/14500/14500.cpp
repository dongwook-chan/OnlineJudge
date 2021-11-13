#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int paper[500][500];
bool v[500][500];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int ans;

void dfs(int y, int x, int acc, int depth) {
    if (depth == 3) {
        ans = max(ans, acc + paper[y][x]);
        return;
    }

    v[y][x] = true;

    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) continue;
        if (v[ny][nx]) continue;

        dfs(ny, nx, acc + paper[y][x], depth + 1);
    }

    v[y][x] = false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            //cout << "start dfs for vertex" << y << ", " << x << endl;
            cin >> paper[y][x];
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            dfs (y, x, 0, 0);
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x + 2 < M; ++x) {
            int acc = paper[y][x] + paper[y][x + 1] + paper[y][x + 2];
            
            if (0 < y - 1 && y - 1 < N) {
                ans = max(ans, acc + paper[y - 1][x + 1]);
            }
            if (0 < y + 1 && y + 1 < N) {
                ans = max(ans, acc + paper[y + 1][x + 1]);                                
            }
        }
    }

    for (int y = 0; y + 2 < N; ++y) {
        for (int x = 0; x < M; ++x) {
            int acc = paper[y][x] + paper[y + 1][x] + paper[y + 2][x];
            
            if (0 < x - 1 && x - 1 < N) {
                ans = max(ans, acc + paper[y + 1][x - 1]);
            }
            if (0 < x + 1 && x + 1 < N) {
                ans = max(ans, acc + paper[y + 1][x + 1]);                                
            }
        }
    }

    cout << ans;
    return 0;
}