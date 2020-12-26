#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    int ctr[10] = {0};
    for(int M = A * B * C; M; M /= 10){
        ++ctr[M % 10];
    }

    for(int i = 0; i < 10; ++i){
        cout << ctr[i] << '\n';
    }

    return 0;
}