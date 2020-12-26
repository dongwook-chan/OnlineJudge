#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    if(N < 10) {
        cout << N;
        return 0;
    }

    int ctr = 0;
    for(int n = 1; n <= N; ++n){
        string s = to_string(n);

        int dif = s[1] - s[0];
        int i;
        for(i = 1; i < s.length() - 1; ++i){
            if(dif != s[i + 1] - s[i]) break;
        }

        if(i == s.length() - 1){
            ++ctr;
        }
    }

    cout << ctr + 9;
    return 0;
}