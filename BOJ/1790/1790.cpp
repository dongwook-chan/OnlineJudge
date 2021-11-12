#include <iostream>
#include <string>

using namespace std;

int N, K;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int no = 1; no <= N; ++no) {
        string no_str = to_string(no);
        for (char c : no_str) {
            if(--K == 0) {
                cout << c;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}