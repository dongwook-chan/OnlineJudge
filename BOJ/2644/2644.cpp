#include <iostream>
#include <vector>

using namespace std;

int n;
int src, dst;
vector<int> adj[101];
bool visited[101];
int ans = -1;

void dfs (int v, int depth) {
    visited[v] = true;

    if (v == dst) {
        ans = depth;
        return;
    }

    for (int u : adj[v]) {
        if (visited[u]) continue;

        dfs (u, depth + 1);
    }
}

int main() {
    cin >> n >> src >> dst;

    int m;
    cin >> m;
    while (m--) {
        int v, u;
        cin >> v >> u;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs (src, 0);

    cout << ans;

    return 0;
}