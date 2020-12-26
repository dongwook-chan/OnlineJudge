#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;

    int sum = 0;
    for(auto c : s){
        sum += c - '0';
    }

    cout << sum;

    return 0;
}