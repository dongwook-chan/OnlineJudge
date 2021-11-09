#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define MAX_NUMBER 1000000

using namespace std;


vector<int> idx_of_number[MAX_NUMBER + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int N;
    cin >> N;

    for (int idx = 0; idx < N; ++idx) {
        int number;
        cin >> number;
        idx_of_number[number].push_back(idx);
    }

    int number = 0;
    for (int sorted_idx = 0; sorted_idx < N; ++sorted_idx) {
        while (true) {
            if (idx_of_number[number].size()) break;
            else ++number;
        }
        sort(idx_of_number[number].begin(), idx_of_number[number].end(), [&sorted_idx](int const &initial_idx1, int const &initial_idx2) -> bool const {return abs(sorted_idx - initial_idx1) > abs(sorted_idx - initial_idx2);});
    }

    number = 0;
    int answer = 0;
    for (int sorted_idx = 0; sorted_idx < N; ++sorted_idx) {
        int initial_idx;
        while (true) {
            if (idx_of_number[number].size()) {
                initial_idx = idx_of_number[number].back();
                idx_of_number[number].pop_back();
                break;
            }
            else{
                ++number;
            }
        }
        int idx_diff = abs(sorted_idx - initial_idx);
        int max_idx_diff = N - 1 - sorted_idx;
        answer = max(answer, min(max_idx_diff, idx_diff));
    }

    cout << answer + 1;

    return 0;
}