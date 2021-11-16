#include <iostream>
#include <vector>

using namespace std;

int N;
int A[1000000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> stk;
    vector<int> ans;
    for (int i = N - 1; i >= 0; --i) {
        int a = A[i];

        while (stk.size() && stk.back() < a) {
            stk.pop_back();
        }

        if(stk.size()) {
            ans.push_back(stk.back());
        }
        else {
            ans.push_back(-1);
        }

        stk.push_back(a);
    }

    for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}