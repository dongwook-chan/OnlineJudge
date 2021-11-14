#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int K;
vector<int> stk;
long long ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    while(K--){
        int no;
        cin >> no;
        if (no) {
            stk.push_back(no);
        }
        else {
            stk.pop_back();
        }
    }

    cout << accumulate(stk.begin(), stk.end(), 0);

    return 0;
}