#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;
    M = N;

    int i = 0;
    do {
        int adj_M = (M / 10) ? M : M * 10;
        M = (M % 10) * 10 + (adj_M / 10 + adj_M % 10) % 10;
        ++i;
    } while (M != N);

    cout << i;
    return 0;
}