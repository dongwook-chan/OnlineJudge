#include <iostream>
#include <string>

using namespace std;

int N;
long long ans;
int no_bounds[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int no;
    for (int i = 0; i < 9; ++i) {
        int no_bound = no_bounds[i + 1];
        for (no = no_bounds[i] ; no < no_bound && no <= N; ++no) {
            ans += i + 1;
        }
    }

    cout << ans;

    return 0;
}