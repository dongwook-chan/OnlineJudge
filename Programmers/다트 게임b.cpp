/*
    1. 바로 continue하지 말고 ch를 append하기
*/

#include <string>
#include <locale>
#include <vector>
#include <iostream>

using namespace std;

vector<int> ret_scores;
int area_to_rep['T' + 1];

void process_token(string &opportunity){
    if(opportunity.empty()) return;    /* 1 */
    //cout << "opp: " << opportunity << endl;
    int score = stoi(opportunity);
    //cout << "score: " << score << endl;
    ret_scores.push_back(score);
    if(score == 10){
        opportunity = opportunity.substr(2, opportunity.size() - 2);
    }
    else{
        opportunity = opportunity.substr(1, opportunity.size() - 1);
    }
    //cout << "trimmed opp: " << opportunity << endl;
    int rep = area_to_rep[opportunity[0]];
    for(int r = 1; r < rep; ++r){
        ret_scores.back() *= score;
        //cout << "ret: " << ret_scores.back() << endl;
    }
    if(opportunity.size() == 2){
        switch(opportunity[1]){
            case '*':
                ret_scores.back() *= 2;
                if(ret_scores.size() > 1){
                    ret_scores[ret_scores.size() - 2] *= 2;
                }
                break;
            case '#':
                ret_scores.back() *= -1;
                break;
        }
    }
    opportunity.clear();
}

int solution(string dartResult) {
    area_to_rep['D'] = 2;
    area_to_rep['T'] = 3;
    string opportunity;
    for(auto ch : dartResult){
        if(isdigit(ch)){
            if(!isdigit(opportunity.back())){
                process_token(opportunity);
            }
        }
        opportunity += ch;      /* 1 */
    }
    process_token(opportunity);
    int answer = 0;
    for(auto ret_score : ret_scores){
        //cout << ret_score << endl;
        answer += ret_score;
    }
    return answer;
}