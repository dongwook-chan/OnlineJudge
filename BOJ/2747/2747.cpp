#include <iostream>
#include <vector>

#define NIL -1

using namespace std;

int fib (int n, vector<int>& lookup){
    if (lookup[n] == NIL){
        if (n <= 1){
            lookup[n] = n;
        }
        else{
            lookup[n] = fib(n - 1, lookup) + fib(n - 2, lookup);
        }
    }
    return lookup[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> lookup (46, NIL);
    cout << fib(n, lookup);

    return 0;
}