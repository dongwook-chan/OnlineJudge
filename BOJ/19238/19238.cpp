#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

//#define DEBUG

using namespace std;

int N, M, F;
bool wall[21][21];
struct point {
    int x, y;
};
point b;
struct client {
    point src, dst;
};
client clients[400];
bool clients_visited[400];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// common
int dist;

// bfs for src
point client_src;
point client_dst;

bool bfs(bool is_dst) {
    vector<int> eligible_clients;
    // 알고리즘 경력이 많은 백준은 특정 위치로 이동할 때 항상 최단경로로만 이동한다.
    bool visited[21][21] = {false};
    visited[b.x][b.y] = true;
    queue<point> q;
    q.push(b);
    while (q.size()) {
        int qs = q.size();
        while (qs--) {
            point p = q.front();
            q.pop();

            if (!is_dst) {  // 손님 태우러
                // 그런 승객이 여러 명이면 그중 행 번호가 가장 작은 승객을, 그런 승객도 여러 명이면 그중 열 번호가 가장 작은 승객을 고른다. 택시와 승객이 같은 위치에 서 있으면 그 승객까지의 최단거리는 0이다. 
                for (int c = 0; c < M; ++c) {
                    if (clients_visited[c]) continue;
                    if (p.x == clients[c].src.x && p.y == clients[c].src.y) {
                        eligible_clients.push_back(c);
                    }
                }
            }
            else {  // 손님 내려주려
                if (p.x == client_dst.x && p.y == client_dst.y) goto end0;
            }

            for (int d = 0; d < 4; ++d) {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];

                if (!(1 <= nx && nx <= N && 1 <= ny && ny <= N)) continue;
                if (visited[nx][ny]) continue;
                if (wall[nx][ny]) continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        if (!is_dst) {  // 손님 태우러
            if (eligible_clients.size()) {
                int client_idx = *min_element(eligible_clients.begin(), eligible_clients.end(), [&eligible_clients] (int const &idx1, int const &idx2) -> bool const{
                    if (clients[idx1].src.x == clients[idx2].src.x) {
                        return clients[idx1].src.y < clients[idx2].src.y;
                    }
                    return clients[idx1].src.x < clients[idx2].src.x;
                });
                clients_visited[client_idx] = true;
                client_src = clients[client_idx].src;
                client_dst = clients[client_idx].dst;
                goto end0;
            }
        }
        else {
            ++dist;
        }
        // 연료는 한 칸 이동할 때마다 1만큼 소모된다.
        --F;
    }
    cout << -1;
    return false;
end0:
    // 연료가 바닥나면 그 날의 업무가 끝난다.
    // 이동하는 도중에 연료가 바닥나면 이동에 실패하고, 그 날의 업무가 끝난다.
    if (F < 0) {
        cout << -1;
        return false;
    }
    return true;
}

int main() {
    cin >> N >> M >> F;
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            cin >> wall[x][y];
        }
    }
    cin >> b.x >> b.y;
    for (int c = 0; c < M; ++c) {
        cin >> clients[c].src.x >> clients[c].src.y;
        cin >> clients[c].dst.x >> clients[c].dst.y;
    }

    // 따라서 백준은 한 승객을 태워 목적지로 이동시키는 일을 M번 반복해야 한다.
    for (int c = 0; c < M; ++c) {
#ifdef DEBUG
        cout << c << "th client\n";
#endif

        // 백준이 태울 승객을 고를 때는 현재 위치에서 최단거리가 가장 짧은 승객을 고른다.
        if (!bfs (false)) return 0;
        b = client_src;
#ifdef DEBUG
        cout << "    to src\n";
        cout << "    " << b.x << ", " << b.y << endl;
        cout << "    fuel: " << F << endl;
        cout << endl;
#endif

        dist = 0;
        if (!bfs (true)) return 0;
        b = client_dst;
        // 한 승객을 목적지로 성공적으로 이동시키면, 그 승객을 태워 이동하면서 소모한 연료 양의 두 배가 충전된다.
        F += 2 * dist;

#ifdef DEBUG
        cout << "    to dst\n";
        cout << "    " << b.x << ", " << b.y << endl;
        cout << "    fuel: " << F << endl;
        cout << endl;
#endif
    }

    cout << F;
    return 0;
}
