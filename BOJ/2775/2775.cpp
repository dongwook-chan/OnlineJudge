// 1. C(28, r)까지 나올 수 있기 때문에 combination table size를 28로 해야

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int combination[28][28] = {0};
    for(int i = 0; i <= 27; ++i){
        combination[i][0] = combination[i][i] = 1;

        for(int j = 1; j < i; ++j){
            combination[i][j] = combination[i - 1][j - 1]  + combination[i - 1][j];
        }
    }

    int T;
    cin >> T;
    while(T--){
        int k, n;
        cin >> k >> n;

        cout << combination[k + n][n - 1] << '\n';
    }

    return 0;
}