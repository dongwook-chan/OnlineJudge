#include <iostream>
#include <vector>

#define NIL -1

using namespace std;

vector<long long> lookup (91, NIL);

int fib (int n){
    if (lookup[n] == NIL){
        if (n <= 1){
            lookup[n] = n;
        }
        else{
            lookup[n] = fib(n - 1) + fib(n - 2);
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

    cout << fib(n);

    return 0;
}