#include <iostream>
#include <string>
#include <queue>
#include <limits.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N, S;
queue<pair<int, int>> bee_q;
queue<pair<int, int>> bear_q_org;
pair<int, int> dst;
int visitable_time[800][800];
bool visited[800][800];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int ans;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    for(int r = 0 ;r < N; ++r){
        string row;
        cin >> row;
        for(int c = 0; c < N; ++c){
            switch(row[c]){
            case 'M':
            bear_q_org.push(make_pair(r, c));
            break;
            case 'H':
            bee_q.push(make_pair(r, c));
            break;
            case 'D':
            dst = make_pair(r, c);
            break;
            }
            switch(row[c]){
            //case 'T': case 'M': case 'H':
            //visitable_time[r][c] = 0;
            //break;
            case 'G': case 'D':
            visitable_time[r][c] = INT_MAX;
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
            visited[r][c] = true;
            visitable_time[r][c] = t;
            for(int d = 0; d < 4; ++d){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || N <= nr || nc < 0 || N <= nc) continue;
                if(visited[nr][nc]) continue;
                bee_q.push(make_pair(nr, nc));
            }
        }
    }
    // debug
    for(int r = 0; r < N; ++r){
        for(int c = 0; c < N; ++c){
            cout << visitable_time[r][c];
        }
        cout << endl;
    }
    // bear
    for(int honey_time = 0; ; ++honey_time){
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> bear_q = bear_q_org;
        for(int t = 0; bear_q.size(); ++t){
            int bear_qs = bear_q.size();
            while(bear_qs--){
                int r = bear_q.front().first;
                int c = bear_q.front().second;
                bear_q.pop();
                visited[r][c] = true;
                if(make_pair(r, c) == dst) {
                    ans = max(ans, honey_time);
                    goto out;
                }
                for(int d = 0; d < 4; ++d){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr < 0 || N <= nr || nc < 0 || N <= nc) continue;
                    if(honey_time + t >= visitable_time[nr][nc]) continue;
                    if(visited[nr][nc]) continue;
                    bear_q.push(make_pair(nr, nc));
                }
            }
        }
    out:
        if(bear_q.empty()) break;
    }
    cout << ans;
    return 0;
}