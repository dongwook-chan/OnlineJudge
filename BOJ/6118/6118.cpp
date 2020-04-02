#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;
int N, M;
vector<pair<int, int>> graph[20001];
int inf = INT_MAX >> 1;
int dist[20001];
int main(){
    // input
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    while(M--){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(make_pair(v, 1));
        graph[v].push_back(make_pair(u, 1));
    }
    // init
    fill(dist + 1, dist + N + 1, inf);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    // dijkstra
    while(pq.size()){
        int w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(dist[u] < w) continue;
        for(auto v : graph[u]){
            if(dist[u] + v.second >= dist[v.first]) continue;
            dist[v.first] = dist[u] + v.second;
            pq.push(make_pair(-dist[v.first], v.first));
        }
    }
    // output
    int max_u = distance(begin(dist), max_element(dist + 1, dist + N + 1));
    int max_ctr = 1;
    for(int u = max_u + 1; u <= N; ++u){
        if(dist[u] == dist[max_u]){
            ++max_ctr;
        }
    }
    cout << max_u << ' ' << dist[max_u] << ' ' << max_ctr;
    return 0;
}