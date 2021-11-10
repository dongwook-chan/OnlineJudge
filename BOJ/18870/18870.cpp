#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int *X_of_idx = new int[1000000];
    unordered_map<int, int> idx_of_X;
    for(int idx = 0; idx < N; ++idx) {
        int X;
        cin >> X;
        X_of_idx[idx] = X;
        idx_of_X[X] = idx;
    }

    int *idx_of_rank = new int[1000000];
    int i = 0;
    for (auto it = idx_of_X.begin(); it != idx_of_X.end(); ++it) {
        idx_of_rank[i++] = it->second;
    }

    int M = idx_of_X.size();

    /*
    for (int i = 0; i < M; ++i) {
        cout << idx_of_rank[i] << " ";
    }
    cout << endl;
    */
    
    sort(idx_of_rank, idx_of_rank + M, [&X_of_idx](int const &idx1, int const &idx2) -> bool const{
        return X_of_idx[idx1] < X_of_idx[idx2];
    });

    /*
    for (int i = 0; i < M; ++i) {
        cout << idx_of_rank[i] << " ";
    }
    cout << endl;
    */

    int *rank_of_idx = new int[1000000];
    for (int rank = 0; rank < M; ++rank) {
        int idx = idx_of_rank[rank];
        rank_of_idx[idx] = rank;
    }

    //cout << "final" << endl;
    for (int idx = 0; idx < N; ++idx) {
        cout << rank_of_idx[idx_of_X[X_of_idx[idx]]] << " ";
    }

    return 0;
}