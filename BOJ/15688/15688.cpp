#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int number_ctr_natural[2000001] = {0};
    int *number_ctr = number_ctr_natural + 1000000;

    while(N--){
        int number;
        cin >> number;
        ++number_ctr[number];
    }

    for (int number = -1000000; number < 1000001;) {
        if (number_ctr[number]--) {
            cout << number << '\n';
        }
        else{
            ++number;
        }
    }

    return 0;
}