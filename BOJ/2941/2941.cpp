#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_set<string> croat = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
    
    string S;
    cin >> S;
    
    int ans = 0;
    for(int i = 0; i < S.length(); ++i){
        ++ans;
        if(i < S.length() - 1 && croat.find(S.substr(i, 2)) != croat.end()){
            ++i;
        }
        else if(i < S.length() - 2 && S.substr(i, 3) == "dz="){
            i += 2;
        }
    }

    cout << ans;
    return 0;
}