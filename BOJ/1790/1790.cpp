#include <iostream>
#include <string>

using namespace std;

int N, K;
int no_bounds[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int no = 1;
    for (int i = 1; i < 10; ++i) {
        for (; no < no_bounds[i] && no <= N; ++no) {
            //cout << K << ", " << no << endl;
            if (K - i <= 0) {
                string no_str = to_string(no);
                cout << no_str[K - 1];

                return 0;
            }
            else {
                K -= i;
            }
        }
    }

    cout << -1;

    return 0;
}