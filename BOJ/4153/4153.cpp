#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int sides[3];

int main () {
    while (true) {
        int a, b, c;
        cin >> sides[0] >> sides[1] >> sides[2];

        if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == 0) {
            break;
        }

        sort (sides, sides + 2);

        for (int i = 0; i < 3; ++i) {
            sides[i] *= sides[i];
        }
        
        string ans;
        if (sides[2] == sides[1] + sides[0]) {
            ans = "right";
        }
        else {
            ans = "wrong";
        }
        cout << ans << '\n';

    }

    return 0;
}