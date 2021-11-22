#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cards[100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum > M) continue;

                ans = max(ans, sum);
            }
        }
    }

    cout << ans;

    return 0;
}