/*
    오답:
        1. 행, 열, 3 X 3 사각형 중에서 하나라도 8개의 숫자가 채워졌다면 남은 숫자 하나를 채우는 방식으로 접근
            ㄴ 입력에 8개의 숫자가 채워진 경우가 없을 수도 있다.
        2. vst에는 1 ~ 9의 숫자가 인덱스로 존재해야 하므로 크기 10으로 선언
        3. 모든 가능한 수를 대입는데 답이 나오지 않았다면 "대입 철회"하고 이전 수로 돌아가기
*/
#include <iostream>
#include <string.h>
using namespace std;
int board[9][9];
bool vst[10];   /* 오답 2 */
bool bf(int r, int c){
    // find next 0
    for(; r < 9; ++r){
        for(; c < 9; ++c){
            if(!board[r][c]){
                goto visit;
            }
        }
        c = 0;
    }
    for(r = 0; r < 9; ++r){
        for(int c = 0; c < 9; ++c){
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
    return true;
visit:
    memset(vst, false, sizeof(vst));  /* 오답 2 */
    for(int c = 0; c < 9; ++c){
        vst[board[r][c]] = true;
    }
    for(int r = 0; r < 9; ++r){
        vst[board[r][c]] = true;
    }
    int r_base = r - r % 3;
    int c_base = c - c % 3;
    for(int r_ofs = 0; r_ofs < 3; ++r_ofs){
        int r = r_base + r_ofs;
        for(int c_ofs = 0; c_ofs < 3; ++c_ofs){
            int c = c_base + c_ofs;
            vst[board[r][c]] = true;
        }
    }
    for(int i = 1; i <= 9; ++i){
        if(!vst[i]){
            board[r][c] = i;
            if(bf(r, c + 1)){
                return true;
            }
        }
    }
    board[r][c] = 0;    /* 오답 3 */
    return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int r = 0 ; r < 9; ++r){
        for (int c = 0; c < 9; ++c){
            cin >> board[r][c];
        }
    }
    bf(0, 0);
    return 0;
}