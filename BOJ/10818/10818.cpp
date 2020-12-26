#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> V(N);
    while(N--){
        int I;
        cin >> I;
        V[N] = I;
    }

    cout << *min_element(V.begin(), V.end()) << ' ';
    cout << *max_element(V.begin(), V.end());

    return 0;
}