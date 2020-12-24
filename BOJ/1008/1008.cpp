#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    cout << (unsigned long long double) A / B;

    return 0;
}