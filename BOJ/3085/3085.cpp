#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string brd[50];
int ans;

void eat_row(int y){
	int clr_ctr;
	
	clr_ctr = 1;
	for (int x = 1; x < N; ++x) {
		if (brd[y][x - 1] == brd[y][x]) {
			++clr_ctr;
			ans = max(ans, clr_ctr);
		}
		else {
			clr_ctr = 1;
		}
	}
}

void eat_col(int x){
	int clr_ctr;

	clr_ctr = 1;
	for (int y = 1; y < N; ++y) {
		if (brd[y - 1][x] == brd[y][x]) {
			++clr_ctr;
			ans = max(ans, clr_ctr);
		}
		else {
			clr_ctr = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> brd[i];
	}

	// row 방향 swap
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N - 1; ++x) {
			swap(brd[y][x], brd[y][x + 1]);
			eat_row(x);
			eat_row(x + 1);
			eat_col(y);
			swap(brd[y][x], brd[y][x + 1]);
		}
	}

	// col 방향 swap
	for (int y = 0; y < N - 1; ++y) {
		for (int x = 0; x < N; ++x) {
			swap(brd[y][x], brd[y + 1][x]);
			eat_row(x);
			eat_col(y);
			eat_col(y + 1);
			swap(brd[y][x], brd[y + 1][x]);
		}
	}

	cout << ans;

	return 0;
}