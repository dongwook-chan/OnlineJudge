#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string A, string B){
    if (A.length() == B.length()){
        return A < B;
    }
    else{
        return A.length() < B.length();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string A, B;
    cin >> A >> B;
    string A_rev = A, B_rev = B;
    reverse(A_rev.begin(), A_rev.end());
    reverse(B_rev.begin(), B_rev.end());

    bool addition, res_sign;
    if (A.front() != '-' && B.front() != '-'){
        addition = true;
        res_sign = false;
    }
    else if (A.front() != '-' && B.front() == '-'){
        B = B.substr(1, B.length() - 1);

        addition = false;
        res_sign = cmp(A, B);
    }
    else if (A.front() == '-' && B.front() != '-'){
        A = A.substr(1, A.length() - 1);

        addition = false;
        res_sign = cmp(B, A);
    }
    else if (A.front() == '-' && B.front() == '-'){
        A = A.substr(1, A.length() - 1);
        B = B.substr(1, B.length() - 1);

        addition = true;
        res_sign = true;
    }
    
    string C;
    if(addition){
        int carry = 0;
        while (A.length() || B.length()){
            int a = A.length() ? A.back() - '0' : 0;
            int b = B.length() ? B.back() - '0' : 0;

            int sum = (a + b + carry) % 10;
            carry = (a + b + carry) >= 10;

            C.push_back(sum + '0');

            if(A.length()) A.pop_back();
            if(B.length()) B.pop_back();
        }
        if(carry){
            C.push_back('1');
        }
    }
    else{
        string G = max(A, B, cmp);
        string L = min(A, B, cmp);
        int carry = 0;
        while(G.length() || L.length()){
            int g = G.length() ? G.back() - '0' : 0;
            int l = L.length() ? L.back() - '0' : 0;

            int sum = g - l - carry;
            carry = sum < 0;
            if(sum < 0) sum += 10;

            C.push_back(sum + '0');

            if(G.length()) G.pop_back();
            if(L.length()) L.pop_back();
        }
    }

    while(C.back() == '0'){
        C.pop_back();
    }
    if(res_sign) C.push_back('-');

    reverse(C.begin(), C.end());
    cout << C;
    
    return 0;
}