#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    short ropes[100000];
    for (int i = 0; i < N; ++i) {
        cin >> ropes[i]; 
    }    

    sort(ropes, ropes + N, greater<short>());

    for (int i = 0; i < N; ++i) {
        ropes[i] *= (i + 1); 
    }

    cout << *max_element(ropes, ropes + N);

    return 0;
}