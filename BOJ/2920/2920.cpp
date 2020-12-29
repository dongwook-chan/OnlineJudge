#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int prev, cur;
    cin >> prev >> cur;

    int dif = cur - prev;
    for(int i = 0; i < 6; ++i){
        prev = cur;

        cin >> cur;
        if(cur - prev != dif){
            cout << "mixed";
            return 0;
        }
    }

    switch(dif){
        case 1:
        cout << "ascending";
        break;
        case -1:
        cout << "descending";
        break;
    }

    return 0;
}