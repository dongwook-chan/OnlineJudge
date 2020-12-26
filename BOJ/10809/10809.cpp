#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    vector<int> alpha(26, -1);
    for(int i = 0; i < S.length(); ++i){
        if(alpha[S[i] - 'a'] == -1){
            alpha[S[i] - 'a'] = i;
        }
    }

    for(auto n : alpha){
        cout << n << ' ';
    }

    return 0;
}