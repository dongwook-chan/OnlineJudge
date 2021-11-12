#include <iostream>
#include <string>

using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string tgt_str = to_string(N);

    string new_str;
    for (int no = 1; no <= N; ++no) {
        new_str += to_string(no);
    }

    cout << new_str.find(tgt_str, 0) + 1;

    return 0;
}