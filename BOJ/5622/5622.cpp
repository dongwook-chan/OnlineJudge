#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c_to_i[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

    string S;
    cin >> S;
    int ans = 0;
    for(auto c : S){
        ans += c_to_i[c - 'A'];
    }

    ans += S.length();
    cout << ans;

    return 0;
}