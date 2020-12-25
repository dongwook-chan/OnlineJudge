#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    string s;
    while(T--){
        cin >> s;
        cout << s[0] - '0' + s[2] - '0' << '\n';
    }

    return 0;
}