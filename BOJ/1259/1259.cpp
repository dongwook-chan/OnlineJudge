#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
    begin:
        string s;
        cin >> s;

        if(s == "0") break;

        for(int i = 0; i < s.length() / 2; ++i){
            if(s[i] != s[s.length() - 1 - i]){
                cout << "no\n";
                goto begin;
            }
        }

        cout << "yes\n";
    }


    return 0;
}