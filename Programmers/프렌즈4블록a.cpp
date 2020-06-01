/* 4  rmv도 같이 이동해야 */
/* 5  r에서 nr로 넘어간 후에도 r을 사용함 */
/* 6. boundary check 누락 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m, n;
vector<string> board;
int eq[30][30];
bool rmv[30][30];
int ans;

int solution(int m, int n, vector<string> board) {
    for (int t = 1;; ++t) {
      // 좌우 동일면 eq에 표시
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n - 1; ++c) {
                if (board[r][c] != '0' && board[r][c] == board[r][c + 1]) {
                    eq[r][c] = t;
                }
            }
        }
        // 좌우상하 동일하면 rmv에 표시
        for (int r = 0; r < m - 1; ++r) {
            for (int c = 0; c < n - 1; ++c) {
                if (eq[r][c] == t && eq[r + 1][c] == t && board[r][c] == board[r + 1][c]) {
                    rmv[r][c] = rmv[r][c + 1] = rmv[r + 1][c] = rmv[r + 1][c + 1] = 1;
                }
            }
        }
        // 각 열별로 당기기
        int rmvd = 0;
        for (int c = 0; c < n; ++c) {
            for (int r = m - 1; r >= 0 && board[r][c] != '0';) {    /* 1 */
                for (; r >= 0 && board[r][c] != '0' && !rmv[r][c]; --r);    // 제거 대상 블록 찾기
                if (r == -1 || board[r][c] == '0')        // 없으면 pass
                    break;
                int nr, gap = 0;
                /* 6 */
                for (nr = r; nr >= 0 && rmv[nr][c]; --nr) {    // 제거 대상 블록이 있으면
                    ++gap;
                }
                /* 1 */ /* 5 */
                for (; nr >= 0 && board[nr][c] != '0'; --nr) {    // 보드의 끝이나 쌓인 블록의 끝에 다다를 때까지 제거 대상 블록 만킁 블록 내리기
                    board[nr + gap][c] = board[nr][c];
                    rmv[nr + gap][c] = rmv[nr][c];	/* 4 */
                }
                for (nr = nr + gap; nr >= 0 && board[nr][c] != '0' != -1; --nr) {   /* 5 */
                    board[nr][c] = '0';    /* 3 */
                    rmv[nr][c] = 0;				/* 4 */
                }
                rmvd += gap;
            }
        }
        if (rmvd == 0)
            break;
        ans += rmvd;
    }
    return ans;
}