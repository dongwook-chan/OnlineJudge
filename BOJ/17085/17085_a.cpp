/*
    1. 십자가를 그려나갈 때 dr, dc값에 사이즈를 곱해주기
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 
int R, C;
string board[15];
int cand[225][2], cand_ctr;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int area[] = {1, 5, 9, 13, 17, 21, 25, 29};
int ans;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int r = 0; r < R; ++r){
        cin >> board[r];
        for(int c = 0; c < C; ++c){
            if(board[r][c] == '#'){
                cand[cand_ctr][0] = r;
                cand[cand_ctr][1] = c;
                ++cand_ctr;
            }
        }
    }
    for(int i1 = 0; i1 < cand_ctr; ++i1){
        int r1 = cand[i1][0];
        int c1 = cand[i1][1];
        //cout << r1 << ", " << c1 << endl;
        int max_sz1;
        for(int sz1 = 0; ; ++sz1){
            for(int d = 0; d < 4; ++d){
                int nr1 = r1 + dr[d] * sz1; // 1.
                int nc1 = c1 + dc[d] * sz1; // 1.
                if (nr1 < 0 || R <= nr1 || nc1 < 0 || C <= nc1 || board[nr1][nc1] == '.') {
                    max_sz1 = sz1 - 1;
                    goto next_point1;
                }
            }
            for(int d = 0; d < 4; ++d){
                int nr1 = r1 + dr[d] * sz1; // 1.
                int nc1 = c1 + dc[d] * sz1; // 1.
                board[nr1][nc1] = '.';
            }
            for(int i2 = i1 + 1; i2 < cand_ctr; ++i2){
                int r2 = cand[i2][0];
                int c2 = cand[i2][1];
                //cout << "   " << r2 <<  ", " << c2 << endl;
                int max_sz2;
                for(int sz2 = 0; ; ++sz2){
                    for(int d = 0; d < 4; ++d){
                        int nr2 = r2 + dr[d] * sz2; // 1.
                        int nc2 = c2 + dc[d] * sz2; // 1.
                        if(nr2 < 0 || R <= nr2 || nc2 < 0 || C <= nc2 || board[nr2][nc2] == '.') {
                            max_sz2 = sz2 - 1;
                            goto next_point2;
                        }
                    }
                }
            next_point2:
                ans = max(ans, area[sz1] * area[max_sz2]);
            }       
        }
    next_point1:
        for(int sz1 = 0; sz1 <= max_sz1; ++sz1){
            for(int d = 0; d < 4; ++d){
                int nr1 = r1 + dr[d] * sz1; // 1.
                int nc1 = c1 + dc[d] * sz1; // 1.
                board[nr1][nc1] = '#';
            }
        }
    }
    cout << ans;
    return 0;
}
