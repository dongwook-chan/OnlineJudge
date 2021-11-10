#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    string substring[1000];
    for (int i = 0; i < S.size(); ++i) {
        substring[i] = S.substr(i, S.size() - i);
    }

    sort(substring, substring + S.size());

    for (int i = 0; i < S.size(); ++i) {
        cout << substring[i] << '\n';
    }

    return 0;
}