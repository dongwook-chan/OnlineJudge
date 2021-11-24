#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
string maze[100];
bool visited[100][100];
struct point {
    int y;
    int x;
};
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int ans = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        cin >> maze[y];
    }

    visited[0][0] = true;
    queue<point> q;
    q.push({0, 0});

    while (q.size()) {
        //cout << "dist: " << ans << endl;
        int qs = q.size();
        while(qs--) {
            point p = q.front();
            q.pop();

            //cout << p.y << ", " << p.x << endl;

            if (p.y == N - 1 && p.x == M - 1) goto end;
            
            for (int d = 0; d < 4; ++d) {
                int ny = p.y + dy[d];
                int nx = p.x + dx[d];

                //cout << ny << ", " << nx << endl;

                if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) continue;
                if (visited[ny][nx]) continue;
                if (maze[ny][nx] != '1') continue;

                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        ++ans;
    }
end:
    cout << ans;

    return 0;
}