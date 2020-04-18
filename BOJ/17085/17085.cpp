/*
    1. 매번 이중 for문으로 다음 처리해야할 '#'를 찾는다. inner loop(r2, c2)에서 c2는 예외처리를 잘 해주어야 돌아간다.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int R, C;
string board[15];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int area[] = {1, 5, 9, 13, 17, 21, 25, 29};
int ans;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int r = 0; r < R; ++r){
        cin >> board[r];
    }
    for(int r1 = 0; r1 < R; ++r1){
        for(int c1 = 0; c1 < C; ++c1){
            if(board[r1][c1] == '.') continue;
            //cout << "candidate1 " << r1 << ", " << c1 << endl;
            int max_sz1;
            for(int sz1 = 0; ; sz1++){
                // possible to place cross1?
                for(int d = 0; d < 4; ++d){
                    int nr1 = r1 + dr[d] * sz1;
                    int nc1 = c1 + dc[d] * sz1;
                    if(nr1 < 0 || R <= nr1 || nc1 < 0 || C <= nc1 || board[nr1][nc1] == '.') {
                        max_sz1 = sz1 - 1;
                        goto next_point1;
                    }
                }
                //cout << "place cross1 of size " << sz1 << endl;
                // place cross1
                for(int d = 0; d < 4; ++d){
                    int nr1 = r1 + dr[d] * sz1;
                    int nc1 = c1 + dc[d] * sz1;
                    board[nr1][nc1] = '.';
                }
                int c2 = c1 + 1;    // 1.
                for(int r2 = r1; r2 < R; ++r2){
                    for(; c2 < C; ++c2){
                        if(board[r2][c2] == '.') continue;
                        //cout << "   candidate2 " << r2 << ", " << c2 << endl;
                        int max_sz2;
                        for(int sz2 = 0; ; sz2++){
                            //cout << "   size : " << sz2 << endl;
                            // possible to place cross2?
                            for(int d = 0; d < 4; ++d){
                                int nr2 = r2 + dr[d] * sz2;
                                int nc2 = c2 + dc[d] * sz2;
                                //cout << "   " << nr2 << ", " << nc2 << endl;
                                if(nr2 < 0 || R <= nr2 || nc2 < 0 || C <= nc2 || board[nr2][nc2] == '.'){
                                    max_sz2 = sz2 - 1;
                                    //cout << "   place cross2 of size " << max_sz2 << endl;
                                    goto next_point2;
                                }
                            }
                        }
                    next_point2:
                        //cout << "   update aswer" << endl;
                        ans = max(ans, area[sz1] * area[max_sz2]);
                        //cout << "   updated aswer" << endl;
                        continue;
                    }
                    c2 = 0; // 1.
                }
            }
        next_point1:
            for(int sz1 = 0; sz1 <= max_sz1; sz1++){
                for(int d = 0; d < 4; ++d){
                    int nr1 = r1 + dr[d] * sz1;
                    int nc1 = c1 + dc[d] * sz1;
                    board[nr1][nc1] = '#';
                }
            }
        }
    }
    cout << ans;
    return 0;
}