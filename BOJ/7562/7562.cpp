#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

bool visited[300][300];
struct point {
    int y;
    int x;
};
deque<point> q;

int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
        int i;
        cin >> i;
        point src;
        cin >> src.y >> src.x;
        point dst;
        cin >> dst.y >> dst.x;

        memset(visited, false, sizeof(visited));
        q.clear();

        visited[src.y][src.x] = true;
        q.push_back(src);

        int ans = 0;
        while(q.size()) {
            int qs = q.size();
            while (qs--) {
                point v = q.front();
                q.pop_front();

                if (v.x == dst.x && v.y == dst.y) goto end;

                for (int d = 0; d < 8; ++ d) {
                    int ny = v.y + dy[d];
                    int nx = v.x + dx[d];

                    if (!(0 <= ny && ny < i && 0 <= nx && nx < i)) continue;
                    if (visited[ny][nx]) continue;

                    visited[ny][nx] = true;
                    q.push_back({ny, nx});
                }
            }
            ++ans;
        }
    end:
        cout << ans << '\n';
    }    

    return 0;
}