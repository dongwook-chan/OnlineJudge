#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string brd[50];
int ans;

void eat(){
	char clr;
	int clr_ctr;
	
	for (int y = 0; y < N; ++y) {
		clr = -1;
		for (int x = 0; x < N; ++x) {
			if (brd[y][x] == clr) {
				++clr_ctr;
				ans = max(ans, clr_ctr);
			}
			else {
				clr = brd[y][x];
				clr_ctr = 1;
			}
		}
	}

	for (int x = 0; x < N; ++x) {
		clr = -1;
		for (int y = 0; y < N; ++y) {
			if (brd[y][x] == clr) {
				++clr_ctr;
				ans = max(ans, clr_ctr);
			}
			else {
				clr = brd[y][x];
				clr_ctr = 1;
			}
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
			eat();
			swap(brd[y][x], brd[y][x + 1]);
		}
	}

	// col 방향 swap
	for (int y = 0; y < N - 1; ++y) {
		for (int x = 0; x < N; ++x) {
			swap(brd[y][x], brd[y + 1][x]);
			eat();
			swap(brd[y][x], brd[y + 1][x]);
		}
	}

	cout << ans;

	return 0;
}