#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int M = 1; ; ++M) {
        int sum = M;
        for (int M_ = M; M_; M_ /= 10) {
            sum += M_ % 10;
        }
        if (sum == N) {
            cout << M;
            return 0;
        }
    }

    cout << 0;
    return 0;
}