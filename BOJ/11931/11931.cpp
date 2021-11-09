#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool number_ctr_natural[2000001] = {false};
    bool *number_ctr = number_ctr_natural + 1000000;

    int N;
    cin >> N;

    while(N--){
        int number;
        cin >> number;
        number_ctr[number] = true;
    }

    for (int number = 1000000; number >= -1000000; --number){
        if (number_ctr[number]) {
            cout << number << '\n';
        }
    }

    return 0;
}