#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int H, M;
    cin >> H >> M;

    int M_agg = 24 * 60;
    M_agg += H * 60 + M;

    int M_adj = M_agg - 45;
    M_adj %= 24 * 60;

    cout << M_adj / 60 << ' ' << M_adj % 60;

    return 0;
}