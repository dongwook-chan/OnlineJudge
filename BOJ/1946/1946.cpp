#include <iostream>
#include <numeric>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;

        int rank_of_idx[2][100001];
        for (int i = 0; i < N; ++i) {
            cin >> rank_of_idx[i][0];
            cin >> rank_of_idx[i][1];
            --rank_of_idx[i][0];
            --rank_of_idx[i][1];
        }

        sort(rank_of_idx, rank_of_idx + N, [](int const *rank1, int const *rank2) -> bool const {
            return rank1[0] < rank2[0];
        });

    }

    return 0;
}