#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int year;
    cin >> year;

    cout << !(year % 4) && (year % 100);

    return 0;
}