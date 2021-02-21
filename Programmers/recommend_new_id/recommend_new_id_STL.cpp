#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string new_id) {
    // 1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    // 2단계
    string tmp_new_id;
    for(auto c : new_id){
        if(isalnum(c) || c == '-' || c == '_' || c == '.'){
            tmp_new_id += c;
        }
    }
    new_id = tmp_new_id;
    
    // 3단계
    bool is_consecutive =  false;
    tmp_new_id.clear();
    for(auto c : new_id){
        if(c == '.'){
            if(is_consecutive){
                continue;
            }
            else{
                is_consecutive = true;
            }
        }
        else{
            is_consecutive = false;
        }
        tmp_new_id += c;
    }
    new_id = tmp_new_id;
    
    // 4단계
    bool leading_dot = (new_id.front() == '.');
    bool trailing_dot = (new_id.back() == '.');
    new_id = new_id.substr(leading_dot, new_id.length() - leading_dot - trailing_dot);
    
    // 5단계
    new_id += string(new_id.empty(), 'a');
    
    // 6단계
    new_id = new_id.substr(0, 15);
    if(new_id.back() == '.'){
        new_id.pop_back();
    }
    
    // 7단계
    new_id += string(max(0, 3 - int(new_id.length())), new_id.back());
    
    return new_id;
}