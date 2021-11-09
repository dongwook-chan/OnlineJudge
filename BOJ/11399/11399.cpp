#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short N;
    cin >> N;

    short *P = new short[N];

    for(short i = 0; i < N; ++i){
        cin >> P[i];
    }

    sort(P, P + N);

    int sum = 0;
    for(short i = 0; i < N; ++i){
        sum += P[i] * (N - i);
    }

    cout << sum;

    return 0;
}