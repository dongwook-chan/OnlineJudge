#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> str_vec = {
        "\\    /\\",
        " )  ( ')",
        "(  /  )",
        " \\(__)|"
    };

    for(auto str : str_vec){
        cout << str << '\n';
    }

    return 0;
}