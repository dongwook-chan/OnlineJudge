#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;

        int ans = 0;
        int score = 0;
        for(auto c : s){
            switch(c){
                case 'O':
                ans += ++score; 
                break;

                case 'X':
                score = 0;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}