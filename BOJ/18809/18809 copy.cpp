#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX_GARDEN_SIZE 50

using namespace std;

enum TILE {LAKE, NO, YES};
enum COLOR {NONE = -1, GREEN, RED};

int N, M, G, R;
TILE garden[MAX_GARDEN_SIZE][MAX_GARDEN_SIZE];
int land_ctr;
struct point {
    int y, x;
};

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int visited_timestamp[2][MAX_GARDEN_SIZE][MAX_GARDEN_SIZE];
queue<point> colored_tile[2];  // 또한 모든 배양액은 서로 다른 곳에 뿌려져야 한다.
int flower_ctr;
int max_flower_ctr;
void propagate() {
    // 배양액은 매 초마다 이전에 배양액이 도달한 적이 없는 인접한 땅으로 퍼져간다.
    for(int t = 1; colored_tile[GREEN].size() && colored_tile[RED].size(); ++t) {  // 매 초 NOTE: 큐가 비었으면 탐색 종료해야...
        for(int c = 0; c < 2; ++c) {    // 색깔 (green, red)
            int tile_ctr = colored_tile[c].size();
            while(tile_ctr--) {
                point tile = colored_tile[c].front();
                colored_tile[c].pop();  // NOTE: pop 안 해서 무한루프 돎...
                int y = tile.y;
                int x = tile.x;

                for(int d = 0; d < 4; ++d) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if(!(0 <= ny && ny < N && 0 <= nx && nx < M)) continue;
                    if(visited_timestamp[c][ny][nx] != -1) continue;  // 배양액은 매 초마다 이전에 배양액이 도달한 적이 없는 인접한 땅으로 퍼져간다.

                    visited_timestamp[c][ny][nx] = t;
                    
                    if(visited_timestamp[GREEN][ny][nx] == visited_timestamp[RED][ny][nx]) {
                        ++flower_ctr; // 초록색 배양액과 빨간색 배양액이 동일한 시간에 도달한 땅에서는 두 배양액이 합쳐져서 꽃이 피어난다.
                    }
                    else{
                        colored_tile[c].push({ny, nx}); // 꽃이 피어난 땅에서는 배양액이 사라지기 때문에 더 이상 인접한 땅으로 배양액을 퍼트리지 않는다.
                    }
                }
            }
        }
    }
}

vector<point> tile_to_color;
COLOR color_for_tile[10];
void choose_color(int g, int r, int tile_i) {
    if(tile_i == tile_to_color.size()) {
        if(g != G || r != R) return;    // 배양액은 봄이 지나면 사용할 수 없게 되므로 주어진 모든 배양액을 남김없이 사용해야 한다.

        memset(visited_timestamp, -1, sizeof(visited_timestamp));
        colored_tile[0] = queue<point>(); 
        colored_tile[1] = queue<point>();
        flower_ctr = 0;

        for(int i = 0; i < tile_to_color.size(); ++i) {
            int color = color_for_tile[i];
            if(color == NONE) continue;
            
            int y = tile_to_color[i].y;
            int x = tile_to_color[i].x;

            visited_timestamp[color][y][x] = 0;
            colored_tile[color].push({y, x});
        }
        propagate();
        max_flower_ctr = max(max_flower_ctr, flower_ctr);

        return;
    }

    color_for_tile[tile_i] = NONE;
    choose_color(g, r, tile_i + 1);

    if(g + 1 <= G) {
        color_for_tile[tile_i] = GREEN;
        choose_color(g + 1, r, tile_i + 1);
    }

    if(r + 1 <= R) {
        color_for_tile[tile_i] = RED;
        choose_color(g, r + 1, tile_i + 1);
    }
}

int main() {
    cin >> N >> M >> G >> R;
    for(int y = 0; y < N; ++y) {
        for(int x = 0; x < M; ++x) {
            int g;
            cin >> g;
            garden[y][x] = (TILE)g;
            if(garden[y][x] == YES) tile_to_color.push_back({y, x});    // 이 때 배양액을 뿌릴 수 있는 땅은 미리 정해져있다.
            if(garden[y][x] != LAKE) ++land_ctr;
        }
    }

    choose_color(0, 0, 0);

    cout << max_flower_ctr;

    return 0;
}