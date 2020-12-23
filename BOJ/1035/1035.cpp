#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <limits.h>
using namespace std;
string board[5];
unsigned int min_cst[1<<25];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int star_ctr;
int ans = INT_MAX;
// dfs
int dfs_vst[5][5], dfs_vstn;
int dfs_ctr;
void dfs(int r, int c){
    ++dfs_ctr;
    
    dfs_vst[r][c] = dfs_vstn;
    for(int d = 0; d < 4; ++d){
        int nr = r + dr[d], nc = c + dc[d];
        if(nr < 0 || 5 <= nr || nc < 0 || 5 <= nc) continue;
        if(board[nr][nc] == '.') continue;
        if(dfs_vst[nr][nc] == dfs_vstn) continue;
        dfs(nr, nc);
    }
}
void bf(int cst){
    if(cst >= ans) return;

    // visit check
    int bm = 0;
    for(int r = 0; r < 5; ++r){
        for(int c = 0; c < 5; ++c){
            if(board[r][c] == '*'){
                bm |= 1 << (r * 5 + c);
            }
        }
    }
    if(min_cst[bm] <= cst) return;
    min_cst[bm] = cst;

    // dfs check
    for(int r = 0; r < 5; ++r){
        for(int c = 0; c < 5; ++c){
            if(board[r][c] == '*') {
                dfs_ctr = 0;
                ++dfs_vstn;
                dfs(r, c);
                if(star_ctr == dfs_ctr){
                    ans = min(ans, cst);
                }
                goto out;
            }
        }
    }
out:
    ;

    // brute force
    for(int r = 0; r < 5; ++r){
        for(int c = 0; c < 5; ++c){
            if(board[r][c] == '*'){
                for(int d = 0; d < 4; ++d){
                    int nr = r + dr[d], nc = c + dc[d];
                    if(nr < 0 || 5 <= nr || nc < 0 || 5 <= nc) continue;
                    if(board[nr][nc] == '*') continue;
                    // swap
                    swap(board[r][c], board[nr][nc]);
                    bf(cst + 1);
                    // undo swap
                    swap(board[r][c], board[nr][nc]);
                }
            }
        }
    }
}
int main(){
    memset(min_cst, -1, sizeof(int) * 1<<25);
    //cout << min_cst[0] << endl;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int r = 0; r < 5; ++r){
        cin >> board[r];
        for(int c = 0; c < 5; ++c){
            if(board[r][c] == '*'){
                ++star_ctr;
            }
        }
    }
    //cout << star_ctr << endl;
    bf(0);
    cout << ans;
    return 0;
}