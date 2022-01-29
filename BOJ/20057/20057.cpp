#include <iostream>
#include <algorithm>

using namespace std;

enum DIR {HORIZ, VERT};

int N;
int A[500][500];
int dA[500][500];

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

int my[] = {1, 1, -1, -1};
int mx[] = {1, -1, -1, 1};


int ans;

struct travel_spec {
    int y, x, r;
};
travel_spec sand_groups [] = {
    {-1, 1, 1},
    {1, 1, 1},
    {-2, 0, 2},
    {2, 0, 2},
    {0, -2, 5},
    {-1, 0, 7},
    {1, 0, 7},
    {-1, -1, 10},
    {1, -1, 10},
    {0, -1, 0}
};

void wind (int &y, int &x, int d, int rep) {
    while (rep--) {
        y += dy[d];
        x += dx[d];
        
        int sand = A[y][x];
        int alpha = sand;

        if (!sand) continue;
        
        for (auto sand_group : sand_groups) {
            int dy = sand_group.y;
            int dx = sand_group.x;
            int r = sand_group.r;

            int diff_sand;
            if (r) diff_sand = (sand * r) / 100;
            else diff_sand = alpha;

            dy = dy * my[d];
            dx = dx * mx[d];
            
            if (d % 2) swap(dy, dx);

            int ny = y + dy;
            int nx = x + dx;

            if (0 <= ny && ny < N && 0 <= nx && nx < N) {
                dA[ny][nx] += diff_sand;
            }
            else {
                ans += diff_sand;
            }

            alpha -= diff_sand;
        }

        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (!dA[y][x]) continue;
                A[y][x] += dA[y][x];
                dA[y][x] = 0;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> A[y][x];
        }
    }

    int y = N / 2;
    int x = N / 2;
    for (int radius = 1; radius < N; radius += 2) {
        for (int d = 0; d < 4; ++d) {          
            wind (y, x, d, radius + d / 2);
        }
    }
    // extra radius
    wind (y, x, 0, N - 1);

    cout << ans;

    return 0;
}