#include <iostream>
#include <deque>
#include <numeric>

using namespace std;

int N;
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    dq.resize(N);
    iota(dq.rbegin(), dq.rend(), 1);


    while(dq.size() > 1){
        dq.pop_back();
        dq.push_front(dq.back());
        dq.pop_back();
        
    }

    cout << dq[0];

    return 0;
}