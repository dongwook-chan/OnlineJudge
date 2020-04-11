/* 
	1. WA : hori swap, vert cont인 테케는 잘 돌아감
	2. row, col 뒤집음
	3. 원상복귀 누락
	4. 하나 세고 들어갔으니 1부터 scan
	5. 마지막에도 갱신
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string board[50];
int ans;
void eat() {
	// hori cont
	for (int r = 0; r < N; ++r) {
		char ch = board[r][0];
		int ctr = 1;
		for (int c = 1; c < N; ++c) {	// 4.
			if (board[r][c] == ch) {
				++ctr;
			}
			else {
				ans = max(ans, ctr);
				ch = board[r][c];
				ctr = 1;
			}
		}
		ans = max(ans, ctr);	// 5.
	}
	// vert cont
	for (int c = 0; c < N; ++c) {
		char ch = board[0][c];	// 2. 
		int ctr = 1;
		for (int r = 1; r < N; ++r) {	// 4.
			if (board[r][c] == ch) {
				++ctr;
			}
			else {
				ans = max(ans, ctr);
				ch = board[r][c];
				ctr = 1;
			}
		}
		ans = max(ans, ctr);	// 5.
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int r = 0; r < N; ++r) {
		cin >> board[r];
	}
	// hori swap
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N - 1; ++c) {	// -1
			if (board[r][c] != board[r][c + 1]) {
				swap(board[r][c], board[r][c + 1]);
				eat();
				swap(board[r][c], board[r][c + 1]);	// 3
			}
		}
	}
	// vert swap
	for (int c = 0; c < N; ++c) {
		for (int r = 0; r < N - 1; ++r) {	// -1
			if (board[r][c] != board[r + 1][c]) {
				swap(board[r][c], board[r + 1][c]);
				eat();
				swap(board[r][c], board[r + 1][c]);	// 3
			}
		}
	}
	cout << ans;
	return 0;
}
