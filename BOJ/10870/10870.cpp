#include <iostream>

using namespace std;

long long F(int n){
    switch(n){
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return F(n-1) + F(n-2);
    }
}

int main(){
    int n;
    cin >> n;

    cout << F(n);

    return 0;
}