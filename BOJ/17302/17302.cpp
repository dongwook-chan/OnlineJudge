#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
int N, M;
enum MOVE{NONE, ADJ, CROSS};
bool board[2000][2000], white[2000][2000];
bool vst[2000][2000][3];
int dr[] = {-1, 0, 1, 0, 0};
int dc[] = {0, 1, 0, -1, 0};
vector<int> flip[3] = {{}, {0, 1, 2, 3}, {0, 1, 2, 3, 4}};
int ctr[2000][2000];
bool dfs(int r, int c, int vst_ctr){
    bool blocked = true;
    for(int m = 0; m < 3; ++m){
        vst[r][c][m] = true;
        for(auto d : flip[m]){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
            ++ctr[nr][nc];
            board[nr][nc] = 1 - board[nr][nc];
        }
        for(int d = 0; d < 4; ++d){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
            if(vst[nr][nc][m]) continue;
            blocked = false;
            if(dfs(nr, nc, vst_ctr + 1)) return true;
        }
        for(auto d : flip[m]){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
            --ctr[nr][nc];
            board[nr][nc] = 1 - board[nr][nc];
        }
    }
    if(vst_ctr == M * N && memcmp(board, white, sizeof(board)) == 0){
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < M; ++c){
                cout << ctr[r][c];
            }
            cout << '\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    string row;
    for(int r = 0; r < N; ++r){
        cin >> row;
        for(int c = 0; c < M; ++c){
            board[r][c] = row[c] == 'B';
        }
    }
    dfs(0, 0, 0);
    return 0;
}