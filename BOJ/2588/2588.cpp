#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A;
    string B;
    cin >> A >> B;

    for (int i = B.length() - 1; i >= 0; --i){
        cout << A * (B[i] - '0') << '\n';
    }
    cout << A * stoi(B);

    return 0;
}