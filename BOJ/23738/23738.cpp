#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main () {
    string word;
    cin >> word;

    string ans;
    for (char ch : word) {
        switch (ch) {
            case 'B':
                ans.push_back('v');
                break;
            case 'E':
                ans.append("ye");
                break;
            case 'H':
                ans.push_back('n');
                break;
            case 'P':
                ans.push_back('r');
                break;
            case 'C':
                ans.push_back('s');
                break;
            case 'Y':
                ans.push_back('u');
                break;
            case 'X':
                ans.push_back('h');
                break;
            default:
                ans.push_back(tolower(ch));
                break;
        }
    }

    cout << ans;

    return 0;
}