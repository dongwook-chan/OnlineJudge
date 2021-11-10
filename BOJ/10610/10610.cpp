#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string number;
    cin >> number;

    sort(number.begin(), number.end(), greater<char>());

    if (number.back() != '0') {
        cout << -1;
    }
    else {
        cout << number;
    }

    return 0;
}