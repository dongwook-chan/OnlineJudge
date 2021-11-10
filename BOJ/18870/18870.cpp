#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int Xs[1000000];
    set<int> Xs_sorted;
    for(int i = 0; i < N; ++i) {
        int X;
        cin >> X;
        Xs[i] = X;
        Xs_sorted.insert(X);
    }

    for (int i = 0; i < N; ++i) {
        cout << distance(Xs_sorted.begin(), Xs_sorted.find(Xs[i])) << ' ';
    }

    return 0;
}