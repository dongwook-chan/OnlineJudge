#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

#define MAX_SIZE 50

using namespace std;

string pool[MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

struct point {
    int y, x;
};

int N, M;
int contained_water_volume;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int contain_water(char water, point p) {
    queue<point> q;
    visited[p.y][p.x] = true;
    q.push(p);

    bool is_contained = true;
    vector<point>contained_water_location; 

    int contained_water_volume = 0;
    while(q.size()) {
        int qs = q.size();
        while(qs--) {
            point p = q.front();
            q.pop();

            contained_water_location.push_back(p);
            ++contained_water_volume;

            for(int d = 0; d < 4; ++d) {
                int ny = p.y + dy[d];
                int nx = p.x + dx[d];

                if(!(0 <= ny && ny < N && 0 <= nx && nx < M)) {
                    is_contained = false; // NOTE: goto로 bfs바로 나가버렸다가 visited체크 제대로 못 함 ㅜㅜ..
                    continue;
                }
                if(pool[ny][nx] >= water) continue;
                if(visited[ny][nx]) continue;

                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    if(!is_contained) return 0;

    for(point p : contained_water_location) {
        ++pool[p.y][p.x];
    }
    return contained_water_volume;
}

int main() {
    cin >> N >> M;
    for(int y = 0; y < N; ++y) {
        cin >> pool[y];
    }

    for(char water = '1'; water <= '9'; ++water) {
        memset(visited, false, sizeof(visited));
        for(int y = 0; y < N; ++y) {
            for(int x = 0; x < M; ++x) {
                if(pool[y][x] >= water) continue;
                if(visited[y][x]) continue;
                contained_water_volume += contain_water(water, {y, x});
            }
        }
    }

    cout << contained_water_volume;

    return 0;
}