#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    --K;

    //int A[5000000];
    int *A = new int[5000000];
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    nth_element(A, A + K, A + N);

    cout << A[K];

    return 0;
}