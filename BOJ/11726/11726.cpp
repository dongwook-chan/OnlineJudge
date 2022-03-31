#include <iostream>

#define MAX_NO 1000

using namespace std;

int n;
int table[MAX_NO + 1];

int modulo(int n) {
    return n % 100007;
}

int lookup(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (table[n]) return table[n];

    table[n] = modulo(modulo(lookup(n - 1)) + modulo(lookup(n - 2)));
    return table[n];
}

int main(){
    cin >> n;

    cout << lookup(n);

    return 0;
}
