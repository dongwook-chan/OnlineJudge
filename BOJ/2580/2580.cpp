/*
    오답:

*/
#include <iostream>
#include <queue>
using namespace std;
int board[9][9];
int row_ctr[9],     row_sum[9];
int col_ctr[9],     col_sum[9];
int sq_ctr[3][3],   sq_sum[3][3];
queue<pair<int, int>> q;
void update(int r, int c){
    ++row_ctr[r];           row_sum[r] += board[r][c];
    ++col_ctr[c];           col_sum[c] += board[r][c];
    ++sq_ctr[r / 3][c / 3]; sq_sum[r / 3][c / 3] += board[r][c];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int r = 0; r < 9; ++r){
        for(int c = 0; c < 9; ++c){
            cin >> board[r][c];
            if(board[r][c]){
                update(r, c);
            }
            else{
                q.push(make_pair(r, c));
            }
        }
    }
    while(q.size()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(row_ctr[r] == 8){
            board[r][c] = 45 - row_sum[r];
            update(r, c);
        }
        else if(col_ctr[c] == 8){
            board[r][c] = 45 - col_sum[c];
            update(r, c);
        }
        else if(sq_ctr[r / 3][c / 3] == 8){
            board[r][c] = 45 - sq_sum[r / 3][c / 3];
            update(r, c);
        }
        else{
            q.push(make_pair(r, c));
        }
    }
    for(int r = 0; r < 9; ++r){
        for(int c  = 0; c < 9; ++c){
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
    return 0;
}