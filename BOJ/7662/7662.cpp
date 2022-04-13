#include <iostream>
#include <set>

using namespace std;

int T, k;
multiset<int> Q;

int main() {
    cin >> T;
    while(T--) {
        cin >> k;
        while(k--) {
            char op;
            int n;
            cin >> op >> n;

            switch(op){
            case 'I':
                Q.insert(n);
                break;
                
            case 'D':
                if(Q.empty()) continue;

                switch(n) {
                case -1:    // 'D -1'는 Q 에서 최솟값을 삭제
                    Q.erase(Q.begin());
                    break;

                case 1:     // 'D 1'는 Q에서 최댓값을 삭제
                    Q.erase(--Q.end());
                    break;
                }
                break;
            }
        }
        if(Q.empty()) cout << "EMPTY";
        else cout << *(--Q.end()) << ' ' << *(Q.begin());
        cout << '\n';
    }

    return 0;
}