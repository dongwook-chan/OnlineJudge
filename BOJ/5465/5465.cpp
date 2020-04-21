/*
    1. WA - 11% 나무에 벌이 못 가도록 해야
            갈수 있는 곳 없는 곳 조건이 복잡하고 곰이 갈 수 있는 곳과 벌이 갈 수 있는 곳이 다르기 때문에 visitable_bear, visitable_bee 따로 구하기
    2. TLE 
*/
#include <iostream>
#include <string>
#include <queue>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N, S;
pair<int, int> src, dst;
bool visitable_bear[800][800], visitable_bee[800][800];
unsigned int visitable_time[800][800];
int visited[800][800];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int ans;
int main(){
    memset(visitable_time, -1, sizeof(visitable_time));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    queue<pair<int, int>> bee_q;
    for(int r = 0 ;r < N; ++r){
        string row;
        cin >> row;
        for(int c = 0; c < N; ++c){
            switch(row[c]){
            case 'T':   // 나무
            visitable_bear[r][c] = false;
            visitable_bee[r][c] = false;
            break;
            case 'G':   // 풀밭
            visitable_bear[r][c] = true;
            visitable_bee[r][c] = true;
            break;
            case 'M':   // 곰돌이
            visitable_bear[r][c] = true;
            visitable_bee[r][c] = false;
            src = make_pair(r, c);
            break;
            case 'D':   // 곰돌이 집
            visitable_bear[r][c] = true;
            visitable_bee[r][c] = false;
            dst = make_pair(r, c);
            break;
            case 'H':   // 벌집   
            visitable_bear[r][c] = false;
            visitable_bee[r][c] = false;
            bee_q.push(make_pair(r, c));
            break;
            }
        }
    }
    // bee
    for(int t = 0; bee_q.size(); t += S){
        int bee_qs = bee_q.size();
        while(bee_qs--){
            int r = bee_q.front().first;
            int c = bee_q.front().second;
            bee_q.pop();
            visitable_time[r][c] = t;
            for(int d = 0; d < 4; ++d){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || N <= nr || nc < 0 || N <= nc) continue;
                if(!visitable_bee[nr][nc]) continue;
                if(visited[nr][nc]) continue;
                if(make_pair(nr, nc) == dst) continue;
                visited[nr][nc] = true;
                bee_q.push(make_pair(nr, nc));
            }
        }
    }
    // debug
    /*
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            cout << visitable_time[r][c] << '\t';
        }
        cout << endl;
    }
    */
    // bear
    for(int honey_time = 0; ; honey_time += S){
        memset(visited, false, sizeof(visited));
        visited[src.first][src.second] = honey_time + 2;
        queue<pair<int, int>> bear_q;
        bear_q.push(src);
        // bfs
        for(int t = 1; bear_q.size(); ++t){ //
            int bear_qs = bear_q.size();
            while(bear_qs--){
                int r = bear_q.front().first;
                int c = bear_q.front().second;
                bear_q.pop();
                if(make_pair(r, c) == dst) goto next_honey_time;
                for(int d = 0; d < 4; ++d){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr < 0 || N <= nr || nc < 0 || N <= nc) continue;
                    if(!visitable_bear[nr][nc]) continue;
                    if(honey_time + t >= visitable_time[nr][nc]) continue;
                    if(visited[nr][nc] == honey_time + 2) continue;
                    visited[nr][nc] = honey_time + 2;
                    bear_q.push(make_pair(nr, nc));
                }
            }
        }
        ans = honey_time / S - 1;
        break;
    next_honey_time:
        continue;
    }
    cout << ans;
    return 0;
}