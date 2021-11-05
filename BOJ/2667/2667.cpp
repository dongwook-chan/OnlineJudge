#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string map[25];
int map_size;
bool visited[25][25];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int complex_ctr;
int complex_size[625];

void dfs(int y, int x) {
    visited[y][x] = true;
    ++complex_size[complex_ctr];

    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (!(0 <= ny && ny < map_size && 0 <= nx && nx < map_size)) continue;
        if (visited[ny][nx]) continue;
        if (map[ny][nx] != '1') continue;

        dfs(ny, nx); 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> map_size;

    for (int y = 0; y < map_size; ++y){
        cin >> map[y];
    }

    for (int y = 0; y < map_size; ++y){
        for (int x = 0; x < map_size; ++x){
            if (visited[y][x]) continue;
            if (map[y][x] != '1') continue;

            dfs(y, x);
            ++complex_ctr;
        }
    }

    sort(complex_size, complex_size + complex_ctr);

    cout << complex_ctr << '\n';
    for (int i = 0; i < complex_ctr; ++i) {
        cout << complex_size[i] << '\n';
    }   

    return 0;
}