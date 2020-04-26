#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main(){
    string a[2], b[2];
    cout << memcmp(a, b, sizeof(a));
    return 0;
}