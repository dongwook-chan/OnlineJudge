#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, X, A;
    cin >> N >> X;
    while(N--){
        cin >> A;
        if (A < X) cout << A << ' ';
    }

    return 0;
}