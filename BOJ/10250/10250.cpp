#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int H, W, N;
        cin >> H >> W >> N;
        int X = (N - 1) / H + 1;
        int Y = (N - 1) % H + 1;
        string pad = (X / 10) ? "" : "0";
        cout << to_string(Y) + pad + to_string(X) << '\n';
    }
}