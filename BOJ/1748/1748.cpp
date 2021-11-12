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

    for (int no = 1; no <= N; ++no) {
        ans += to_string(no).size();
    }

    cout << ans;

    return 0;
}