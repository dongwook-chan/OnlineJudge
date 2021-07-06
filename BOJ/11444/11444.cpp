#include <iostream>
#include <string.h>

using namespace std;

int power[2][2];
int base[2][2] = {{1, 1}, {1, 0}};
int identity[2][2] = {{1, 0}, {0, 1}};

void multiply(int operand[][2]){
    int tmp[2][2];

    for (int l = 0; l < 2; ++l) {        
        for (int n = 0; n < 2; ++n) {
            long long sum = 0;
            for (int m = 0; m < 2; ++m) {
                sum += ((long long) power[l][m] * operand[m][n]) % 1000000007;     // 곱셈의 결과가 int 범위 벗어날 수 있다.
            }
            tmp[l][n] = sum % 1000000007;       // 덧셈의 결과가 int를 벗어날 수 있다.
        }
    }

    memcpy(power, tmp, sizeof(int) * 4);
}

void divide_conquer(long long exponent){
    if (exponent == 0){
        memcpy(power, identity, sizeof(int) * 4);
        return;
    }

    divide_conquer(exponent / 2);

    multiply(power);

    if (exponent % 2) {
        multiply(base);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    divide_conquer(n - 1);

    int ans = power[0][0];
    cout << ans;

    return 0;
}