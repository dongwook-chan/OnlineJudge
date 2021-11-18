#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
queue<int> q;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    //for (int i = N - 1; i >= 0; --i){
    for (int i = 1; i <= N; ++i){
        q.push(i);
    }    
    
    while(q.size()){
        for(int i = 0; i < K - 1; ++i){
            //cout << q.back() << ' ';
            q.push(q.front());
            q.pop();
        }
        //cout << q.back() << ' ';
        ans.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < ans.size() - 1; ++i) {
        cout << ans[i] << ", ";
    }
    cout << ans.back() << ">";

    return 0;
}