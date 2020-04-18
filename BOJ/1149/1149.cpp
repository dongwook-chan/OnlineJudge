#include <iostream>
#include <algorithm>
using namespace std;
int N;
enum COLOR{R, G, B};
int cst[1001][3];
//int R[1001], G[1001], B[1001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> cst[i][R] >> cst[i][G] >> cst[i][B];
    }
    for(int i = 1; i <= N; ++i){
        cst[i][R] += min(cst[i - 1][G], cst[i - 1][B]);
        cst[i][G] += min(cst[i - 1][R], cst[i - 1][B]);
        cst[i][B] += min(cst[i - 1][R], cst[i - 1][G]);
    }
    cout << min({cst[N][R], cst[N][G], cst[N][B]});
    return 0;
}