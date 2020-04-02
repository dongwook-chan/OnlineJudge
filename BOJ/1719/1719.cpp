/*
    오답 :
        1. 플로이드 와샬 문제가 아니다.
            ㄴ 표의 의미를 잘 보자 행, 열이 가르키는 노드 간 최단거리가 아님!
        2. 양방향 그래프이므로 src -> dst 와 dst -> src 경로가 동일
            ㄴ src -> dst 경로에서 dst 전에 마지막으로 방문한 노드는
            ㄴ dst -> src 경로에서 src 다음으로 방문한 노드와 동일
*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
int n, m;
vector<pair<int, int>> graph[201];
int inf = INT_MAX / 2;
int dist[201];
int stopover[201][201];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    for(int src = 1; src <= n; ++src){
        // init
        fill(dist + 1, dist + n + 1, inf);
        dist[src] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, src));
        // dijkstra
        while(pq.size()){
            int w = -pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(dist[u] < w) continue;
            for(auto v : graph[u]){
                if(dist[u] + v.second >= dist[v.first]) continue;
                dist[v.first] = dist[u] + v.second;
                stopover[src][v.first] = u;
                pq.push(make_pair(-dist[v.first], v.first));
            }
        }
    }
    // output
    for(int src = 1; src <= n; ++src){
        for(int dst = 1; dst <= n; ++dst){
            if(src == dst){
                cout << "- ";
            }
            else{
                cout << stopover[dst][src] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}