#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    string names[100000];
    int scores[100000][3];
    for (int i = 0; i < N; ++i) {
        cin >> names[i];
        cin >> scores[i][0];
        cin >> scores[i][1];
        cin >> scores[i][2];
    }

    int idx[100000];
    iota(idx, idx + N, 0);



    stable_sort(idx, idx + N, [&names](int const &idx1, int const &idx2) -> bool const {
        return names[idx1] < names[idx2];
    });

    stable_sort(idx, idx + N, [&scores](int const &idx1, int const &idx2) -> bool const {
        return scores[idx1][2] > scores[idx2][2];
    });

    stable_sort(idx, idx + N, [&scores](int const &idx1, int const &idx2) -> bool const {
        return scores[idx1][1] < scores[idx2][1];
    });

    stable_sort(idx, idx + N, [&scores](int const &idx1, int const &idx2) -> bool const {
        return scores[idx1][0] > scores[idx2][0];
    });

    
   
    /*
    stable_sort(idx, idx + N, [&scores, &names](int const &idx1, int const &idx2) -> bool const {
        if (scores[idx1][0] == scores[idx2][0]) {
            if (scores[idx1][1] == scores[idx2][1]) {
                if (scores[idx1][2] == scores[idx2][2]) {
                    return names[idx1] < names [idx2];
                }
                else return scores[idx1][2] > scores[idx2][2]; 
            }
            else return scores[idx1][1] < scores[idx2][1]; 
        }
        else return scores[idx1][0] > scores[idx2][0];
    });
    */

    for (int i = 0; i < N; ++i) {
        cout << names[idx[i]] << '\n';
    }

    return 0;
}