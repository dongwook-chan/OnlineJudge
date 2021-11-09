#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool *number_ctr_natural = new bool[20000001];
    bool *number_ctr = number_ctr_natural + 10000000;

    int N;
    cin >> N;
    
    while (N--) {
        int number;
        cin >> number;
        number_ctr[number] = true;
    }

    int M;
    cin >> M;

    while (M--) {
        int number;
        cin >> number;
        cout << number_ctr[number] << ' ';
    }

    return 0;
}