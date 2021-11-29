#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long sides[3];

int main () {
    while (true) {
        cin >> sides[0] >> sides[1] >> sides[2];

        if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == 0) {
            break;
        }

        sort (sides, sides + 2);
        
        if (sides[2] * sides[2] == sides[1] * sides[1] + sides[0] * sides[0]) {
            cout << "right" << endl;
        }
        else {
            cout << "wrong" << endl;
        }
    }
    return 0;
}