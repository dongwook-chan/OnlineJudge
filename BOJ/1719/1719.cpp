#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int n, m;
int inf = INT_MAX / 2;
int dp[201][201];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    // 초기화
    for(int u = 1; u <= n; ++u){
        fill(dp[u] + 1, dp[u] + n + 1, inf);
        dp[u][u] = 0;
    }
    // 입력
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        dp[v][u] = dp[u][v] = min(dp[u][v], c);
    }
    // 플로이드-와샬
    for(int w = 1; w <= n; ++w){
        for(int u = 1; u <= n; ++u){
            for(int v = 1; v <= n; ++v){
                dp[u][v] = min(dp[u][v], dp[u][w] + dp[w][v]);
            }
        }
    }
    // 출력
    for(int u = 1; u <= n; ++u){
        for(int v = 1; v <= n; ++v){
            if(u == v){
                cout << "- ";
            }
            else{
                cout << dp[u][v] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}