#include <iostream>
#include <set>
#include <queue>

using namespace std;

set<int> adj_list [1001];
bool visited [1001];

void dfs(int n1) {
    cout << n1 << ' ';
    visited[n1] = true;

    for (auto n2 : adj_list[n1]) {
        if (visited[n2]) continue;

        dfs(n2);
    }
}

void bfs(int n0) {
    queue<int> q;
    visited[n0] = true;
    q.push(n0);


    while(!q.empty()) {
        int n1 = q.front();
        q.pop();
        cout << n1 << ' ';

        for (auto n2 : adj_list[n1]) {
            if (visited[n2]) continue;

            visited[n2] = true;
            q.push(n2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        int n1, n2;
        cin >> n1 >> n2;

        adj_list[n1].emplace(n2);
        adj_list[n2].emplace(n1);
    }

    dfs(V);

    cout << '\n';
    fill(visited, visited + 1001, false);

    bfs(V);

    return 0;
}