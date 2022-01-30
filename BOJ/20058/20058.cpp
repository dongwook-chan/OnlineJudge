#include <iostream>
#include <algorithm>

#define MAX_SIZE 64

using namespace std;

int N, Q;
int ices[MAX_SIZE][MAX_SIZE];
int tmp_ices[MAX_SIZE * 4];
int two_power__[] = {0, 1, 2, 4, 8, 16, 32, 64};
int *two_power_ = two_power__ + 1;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
bool visited[MAX_SIZE][MAX_SIZE];
bool is_melted[MAX_SIZE][MAX_SIZE];

bool out_of_map (int ny, int nx) {
    return !(0 <= ny && ny < two_power_[N] && 0 <= nx && nx < two_power_[N]);
}

int chunk_size;
void dfs (int y, int x) {
    visited[y][x] = true;
    ++chunk_size;

    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (out_of_map(ny, nx)) continue;
        if (visited[ny][nx]) continue;
        if (!ices[ny][nx]) continue;

        dfs(ny, nx);
    }
}

// 얼음양 0 밑으로 못 떨어지게 해야x
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    for (int y = 0; y < two_power_[N]; ++y) {
        for (int x = 0; x < two_power_[N]; ++x) {
            cin >> ices[y][x];
        }
    }

    while (Q--) {
        int L;
        cin >> L;

        // 1. 회전
        // 기준점 잡기
        for (int y = 0; y < two_power_[N]; y += two_power_[L]) {
            for (int x = 0; x < two_power_[N]; x += two_power_[L]) {
                for (int z = 0; z < two_power_[L - 1]; ++z) {
                    // ices -> tmp_ices
                    int ny = y + z;
                    int nx = x + z;
                    int i = 0;
                    for (int d = 0; d < 4; ++d) {
                        for (int r = 0; r < two_power_[L] - 1 - 2 * z; ++r) {
                            tmp_ices[i++] = ices[ny][nx];
                            ny += dy[d];
                            nx += dx[d];
                        }
                    }

                    // rotate
                    rotate(tmp_ices, tmp_ices + i - two_power_[L] + 1 + 2 * z, tmp_ices + i);

                    // tmp_ices -> ices 
                    ny = y + z;
                    nx = x + z;
                    i = 0;
                    for (int d = 0; d < 4; ++d) {
                        for (int r = 0; r < two_power_[L] - 1 - 2 * z; ++r) {
                            ices[ny][nx] = tmp_ices[i++];
                            ny += dy[d];
                            nx += dx[d];
                        }
                    }
                }
            }
        }
        
        // 2. 얼음 녹음
        for (int y = 0; y < two_power_[N]; ++y) {
            for (int x = 0; x < two_power_[N]; ++x) {
                if (!ices[y][x]) continue;

                int ctr = 0;
                for (int d = 0; d < 4; ++d) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (out_of_map(ny, nx)) continue;
                    if (ices[ny][nx]) ++ctr;
                }
                if (ctr < 3) {
                    is_melted[y][x] = true;
                }
            }
        }

        for (int y = 0; y < two_power_[N]; ++y) {
            for (int x = 0; x < two_power_[N]; ++x) {
                if (is_melted[y][x]) {
                    --ices[y][x];
                    is_melted[y][x] = false;
                }
            }
        }
    }
    
    int sum_ices = 0;
    for (int y = 0; y < two_power_[N]; ++y) {
        for (int x = 0; x < two_power_[N]; ++x) {
            sum_ices += ices[y][x];
        }
    }
    cout << sum_ices << '\n';

    int max_chunk_size = 0;
    for (int y = 0; y < two_power_[N]; ++y) {
        for (int x = 0; x < two_power_[N]; ++x) {
            if (visited[y][x]) continue;
            if (!ices[y][x]) continue;

            chunk_size = 0;
            dfs (y, x);
            max_chunk_size = max(max_chunk_size, chunk_size);
        }
    }
    cout << max_chunk_size << '\n';

    return 0;
}