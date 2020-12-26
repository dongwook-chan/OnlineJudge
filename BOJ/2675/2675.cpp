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
        int R;
        cin >> R;

        string S;
        cin >> S;

        string ans;
        for(auto c : S){
            ans += string(R, c);
        }

        cout << ans << '\n';
    }
    return 0;
}