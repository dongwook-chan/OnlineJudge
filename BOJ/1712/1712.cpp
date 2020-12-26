#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    if(B >= C){
        cout << -1;
    }
    else{
        cout << A / (C - B) + 1;
    }

    return 0;
}