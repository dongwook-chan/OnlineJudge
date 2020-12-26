#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(9);
    for(int i = 0; i < 9; ++i){
        int n;
        cin >> n;
        v[i] = n;
    }

    auto it = max_element(v.begin(), v.end());
    cout << *it << '\n';
    cout << distance(v.begin(), it) + 1;

    return 0;
}