/*
	1. 0과 N+1 인덱스를 BLUE로 채우고 나면 나머지는 1~N
	2. RED case failure for TC 1 : stacked pieces' position must be modified too 
	3. "파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다." -> 이동한 칸은 다시 WHITE, RED, BLUE case로 나뉘어야
*/
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int N, K;
int board[14][14];			// fixed
struct qnode {
	int r, c, k;
};
int position[10][3];		// variable
int idx[14][14][10];		// variable
int height[14][14];			// variable
enum COLOR{BLUE = -1, WHITE = 0, RED};
enum INDEX{INVALID_INDEX = -1};
enum DIRECTION { RIGHT, LEFT, UP, DOWN };
int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };
int nd[] = { LEFT, RIGHT, DOWN, UP };
int ans = -1;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	memset(board[0], BLUE, sizeof(board[0]));			/* 1. */
	memset(board[N + 1], BLUE, sizeof(board[N + 1]));	/* 1. */
	for (int r = 1; r <= N; ++r) {						/* 1. */
		board[r][0] = board[r][N + 1] = BLUE;			/* 1. */
		for (int c = 1; c <= N; ++c) {					/* 1. */
			cin >> board[r][c];
			if (board[r][c] == 2) {
				board[r][c] = BLUE;
			}
		}
	}
	memset(idx, INVALID_INDEX, sizeof(idx));
	int r, c, d;
	for (int k = 0; k < K; ++k) {
		cin >> r >> c >> d;
		position[k][0] = r, position[k][1] = c, position[k][2] = d - 1;
		idx[r][c][k] = 0;
		height[r][c] = 1;
	}
	for(int t = 1; t <= 1000; ++t) {
		for(int k = 0; k < K; ++k){
			// modify position
			int r = position[k][0], c = position[k][1], &d = position[k][2];
			int i = idx[r][c][k], h = height[r][c] - i;
			int nr = r + dr[d], nc = c + dc[d];
			switch (board[nr][nc]) {
			case WHITE:
			WHITE:
				for (int k = 0; k < K; ++k) {
					if (idx[r][c][k] < i) continue;
					// modify idx
					idx[nr][nc][k] = (idx[r][c][k] - i) + height[nr][nc];
					idx[r][c][k] = -1;
					// modify position
					position[k][0] = nr, position[k][1] = nc;	/* 2 */
				}
				// modify height
				height[nr][nc] += h;
				height[r][c] -= h;
				break;
			case RED:
			RED:
				// modify idx
				for (int k = 0; k < K; ++k) {
					if (idx[r][c][k] < i) continue;
					idx[r][c][k] = (height[r][c] - 1 + i) - idx[r][c][k];
				}
				goto WHITE;
			case BLUE:
				// modify position (direction only)
				d = nd[d];
				nr = r + dr[d], nc = c + dc[d];
				switch(board[nr][nc]){	/* 3 */
				case WHITE:			
					goto WHITE;		
				case RED:				/* 3 */
					goto RED;			/* 3 */
				case BLUE:
					continue;
				}
			}
			if (height[nr][nc] >= 4) {
				ans = t;
				goto print_ans;
			}
		}
	}
print_ans:
	cout << ans;
	return 0;
}
