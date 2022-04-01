#include <iostream>
#include <queue>

#define MAX_SIZE 200

using namespace std;

int N;
int r1, c1, r2, c2;
int board[MAX_SIZE][MAX_SIZE];
struct diff {
    int dr, dc;
} directions [] = {
    {-2, -1},
    {-2, 1},
    {0, -2},
    {0, 2},
    {2, -1},
    {2, 1}
};
struct point {
    int r, c;
};
bool visited[MAX_SIZE][MAX_SIZE];

int main() {
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<point> q;
    visited[r1][c1] = true;
    q.push({r1, c1});

    int d = 0;
    while(q.size()) {
        int qs = q.size();
        while(qs--) {
            point p = q.front();
            q.pop();

            int r = p.r;
            int c = p.c;
            
            if(r == r2 && c == c2) {
                goto end;
            }

            for(int i = 0; i < 6; ++i) {
                int dr = directions[i].dr;
                int dc = directions[i].dc;

                int nr = r + dr;
                int nc = c + dc;

                if(!(0 <= nr && nr < N && 0 <= nc && nc < N)) continue;
                if(visited[nr][nc]) continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        ++d;
    }
    cout << -1;
    return 0;
end:
    cout << d;
    return 0;
}