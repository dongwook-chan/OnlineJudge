#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int R, C;
string square[50];
int main(){
    // input
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int r = 0; r < R; ++r){
        cin >> square[r];
    }
    // brute force
    int max_side = min(R, C);
    for(int side = max_side - 1; side >= 0; --side){
        for(int r = 0; r + side < R; ++r){
            for(int c = 0; c + side < C; ++c){
                if(square[r][c] == square[r + side][c] && square[r + side][c] == square[r][c + side] && square[r][c + side] == square[r + side][c + side]){
                    cout << (side + 1) * (side + 1);
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}