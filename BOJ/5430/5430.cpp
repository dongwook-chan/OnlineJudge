#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        string p, x;
        cin >> p >> n >> x;

        bool is_rvs = false;
        int front_ctr = 0;
        int back_ctr = 0;
        for (char ch : p) {
            switch(ch) {
                case 'R':
                    is_rvs = 1 - is_rvs;
                    swap(front_ctr, back_ctr);
                    break;
                case 'D':
                    ++front_ctr;
                    break;
            }
        }

        deque<int> dq;
        string no;
        for (char ch : x) {
            switch(ch) {
                case '[': 
                    break;
                case ',': case ']':
                    if (no.empty()) break;

                    dq.push_back(stoi(no));
                    //cout << stoi(no) << endl;
                    no.clear();
                    break;
                default:
                    no.push_back(ch);
                    break;
            }
        }

        if (is_rvs) {
            reverse(dq.begin(), dq.end());
        }

        //cout << dq.size() << " " << is_rvs << " " << front_ctr << " " << back_ctr << " \n";

        while (dq.size() && front_ctr--) {
            //cout << "popped" << endl;
            dq.pop_front();
        }

        while (dq.size() && back_ctr--) {
            dq.pop_back();
        }

        //cout << dq.size() << " " << front_ctr << " " << back_ctr << " \n";

        if (dq.empty() && (front_ctr || back_ctr)) {
            cout << "error\n";
        }
        else {
            int last_no = dq.back();
            dq.pop_back();

            cout << '[';
            for (int no : dq) {
                cout << no << ',';
            }
            cout << last_no << "]\n";
        }
    }

    return 0;
}