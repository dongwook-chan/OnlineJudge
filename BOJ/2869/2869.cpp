#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, V;
    cin >> A >> B >> V;
    cout << max((V - A) / (A - B), 1) + 1;

    return 0;
}