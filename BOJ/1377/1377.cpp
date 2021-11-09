#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define MAX_NUMBER 1000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int idx_of_number[MAX_NUMBER + 1];
    memset(idx_of_number, -1, sizeof(idx_of_number));

    int N;
    cin >> N;

    for (int idx = 0; idx < N; ++idx) {
        int number;
        cin >> number;
        idx_of_number[number] = idx;
    }

    int number = 0;
    int answer = 0;
    for (int sorted_idx = 0; sorted_idx < N; ++sorted_idx) {
        int initial_idx;
        while (true) {
            if ((initial_idx = idx_of_number[number++]) > -1) {
                break;
            }
        }
        int idx_diff = abs(sorted_idx - initial_idx);
        int max_idx_diff = N - 1 - sorted_idx;
        answer = max(answer, min(max_idx_diff, idx_diff));
    }

    cout << answer + 1;

    return 0;
}