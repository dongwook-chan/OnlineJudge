#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while(N--) {
        string cmd;
        int X;
        int ret;

        cin >> cmd;

        if (cmd == "push"){
            cin >> X;
            q.push(X);
        }
        else if (cmd == "pop") {
            if (q.size()) {
                ret = q.front();
                q.pop();
            }
            else {
                ret = -1;
            }
        }
        else if (cmd == "size") {
            ret = q.size();
        }
        else if (cmd == "empty") {
            ret = q.size() == 0;
        }
        else if (cmd == "front") {
            if (q.size()) {
                ret = q.front();
            }
            else {
                ret = -1;
            }
        }
        else if (cmd == "back") {
            if (q.size()) {
                ret = q.back();
            }
            else {
                ret = -1;
            }
        }

        if (cmd != "push") {
            cout << ret << '\n';
        }
    }

    return 0;
}