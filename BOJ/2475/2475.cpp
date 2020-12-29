#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int square[] = {0, 1, 4, 9, 6, 5, 6, 9, 4, 1};

    int sum = 0;
    for(int i = 0 ; i < 5; ++i){
        int n;
        cin >> n;
        sum += square[n];
    }

    cout << sum % 10;
    return 0;
}