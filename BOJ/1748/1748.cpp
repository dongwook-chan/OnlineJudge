#include <iostream>
#include <string>

using namespace std;

int N;
long long ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    int dgt_ctr, pow_ten;
    for (dgt_ctr = 1, pow_ten = 1; pow_ten * 10 <= N; ++dgt_ctr, pow_ten *= 10) {
        ans += (pow_ten * 10 - pow_ten) * dgt_ctr;
        //cout << (pow_ten * 10 - pow_ten) * dgt_ctr << endl;
    }
    ans += (N - pow_ten + 1) * dgt_ctr;
    //cout << (N - pow_ten + 1) * dgt_ctr << endl;


    cout << ans;

    return 0;
}