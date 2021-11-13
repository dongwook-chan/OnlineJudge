#include <iostream>
#include <numeric>

using namespace std;

int T;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        --x; --y;
        
        int LCM = lcm(M, N);

        int quo_max = LCM / N;
        for (int quo = 0; quo < quo_max; ++quo) {
            int div = M * quo + x;
            if (div % N == y) {
                cout << div + 1 << '\n';
                goto end;                
            }
        }
        cout << -1 << '\n';
    end:
        continue;
    }

    return 0;
}