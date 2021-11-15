#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    while(true){
        string str;
        getline(cin, str);

        if (str[0] == '.') break;
        
        vector<char> stk;

        for (char ch : str) {
            switch(ch){
                case '(':
                    stk.push_back(ch);
                    break;
                case ')':
                    if (stk.size() && stk.back() == '('){
                        stk.pop_back();
                        break;
                    }
                    else{
                        cout << "no\n";
                        goto end;
                    }
                case '[':
                    stk.push_back(ch);
                    break;
                case ']':
                    if (stk.size() && stk.back() == '['){
                        stk.pop_back();
                        break;
                    }
                    else{
                        cout << "no\n";
                        goto end;
                    }
            }
        }
        if (stk.empty()){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    end:
        continue;
    }
    

    return 0;
}