#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool a[42] = {0};
    for(int i = 0; i < 10; ++i){
        int n;
        cin >> n;
        a[n % 42] = true;
    }

    int ctr = 0;
    for(auto n : a){
        if(n) ++ctr;
    }

    cout << ctr;

    return 0;
}