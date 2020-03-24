#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int R, C;
string board[20];
// dfs
bool vst['Z' + 1];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int ans;
void dfs(int r, int c, int cst){
    vst[board[r][c]] = true;
    ans = max(ans, cst);
    for(int d = 0; d < 4; ++d){
        int nr = r + dr[d], nc = c + dc[d];
        if(nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
        if(vst[board[nr][nc]]) continue;
        dfs(nr, nc, cst + 1);
    }
    vst[board[r][c]] = false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int r = 0; r < R; ++r){
        cin >> board[r];
    }
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}