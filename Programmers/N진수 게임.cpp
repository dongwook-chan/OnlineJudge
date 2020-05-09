/*
    1. 0은 같은 방법으로 n진수 전환이 불가능하므로 예외처리해주기
*/

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    char nary_to_string[] = "0123456789ABCDEF";
    
    string acc_str(1, '0');    /* 1 */
    for(int number = 1; acc_str.size() < (t - 1) * m + p; ++ number){
        string str;
        for(int number_ = number; number_; number_ /= n){
            str.push_back(nary_to_string[number_ % n]);
        }
        reverse(str.begin(), str.end());
        acc_str.append(str);
    }
    string answer;
    for(int t_ = 0; t_ < t; ++t_){
        answer.push_back(acc_str[t_ * m + (p - 1)]);
    }
    return answer;
}