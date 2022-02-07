#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string a;
    cin >> a;
    while(--N) {
        string b;
        cin >> b;
        
        for(int i = 0; i < a.size(); ++i) {
            if (a[i] == '?') continue;
            if (a[i] != b[i]) a[i] = '?';
        }
    }

    cout << a;

    return 0;
}