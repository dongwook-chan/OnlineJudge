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

    int no = 1;
    for (int i = 1; i < 9; ++i) {
        for (; no < no_bounds[i] && no <= N; ++no) {
            ans += i;
        }
    }

    cout << ans;

    return 0;
}