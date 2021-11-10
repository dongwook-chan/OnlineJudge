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
            cin >> rank_of_idx[0][i];
            cin >> rank_of_idx[1][i];
        }

        bool is_accepted_idx[100001] = {false};
        bool is_rejected_idx[100001] = {false};
        int idx_of_rank[2][100001];
        iota(idx_of_rank[0] + 1, idx_of_rank[0] + N + 1, 0);
        memcpy(idx_of_rank[1], idx_of_rank[0], sizeof(idx_of_rank[0]));

        for (int i = 0; i < 2; ++i) {
            sort(idx_of_rank[i] + 1, idx_of_rank[i] + N + 1, [&i, &rank_of_idx](int const &index1, int const &index2) -> bool const {
                return rank_of_idx[i][index1] < rank_of_idx[i][index2];
            });
        }

        int answer = 0;

        for (int i = 0; i < 2; ++i) {
            //cout << "ranking" << i << " first\n";
            // rank1을 기준으로 outer for loop
            for (int ranking1 = 1; ranking1 <= N; ++ranking1) {
                //cout << "  ㄴ ranking" << i << ": " << ranking1 << endl;
                // initial_index for ranking1
                // ranking2 for initial_index
                int index1 = idx_of_rank[i][ranking1];
                if (is_accepted_idx[index1] || is_rejected_idx[index1]) continue;

                is_accepted_idx[index1] = true; 
                ++answer;
                
                //cout << "  find any ranking" << !i << " higher than " << rank_of_idx[!i][index1] << endl;
                // any ranking2 higher than ranking2 of initial_index
                for (int ranking2 = rank_of_idx[!i][index1] + 1; ranking2 <= N; ++ranking2) {
                    //cout << "    ㄴ ranking" << !i << ": " << ranking2 << endl;

                    // reject corresponding index2
                    int index2 = idx_of_rank[!i][ranking2];
                    if (is_accepted_idx[index2] || is_rejected_idx[index2]) continue;

                    //cout << "      idx" << index2 << " of ranking" << i << ": " << rank_of_idx[i][index2] << " and ranking" << !i << ": " << rank_of_idx[!i][index2] << " rejected" << endl; 
                    //--answer;
                    is_rejected_idx[index2] = true;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}