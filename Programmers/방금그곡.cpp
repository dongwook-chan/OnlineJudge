/*
    1. 재생 시간 만큼만 재생
*/

#include <string>
#include <vector>
#include <iostream>

enum TOKEN_TYPE{START_TIME, END_TIME, MUSIC_NAME, MUSIC_NOTES};

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string m_tmp;
    for(auto ch : m){
        if(ch == '#'){
            m_tmp.back() += 'a' - 'A';
        }
        else{
            m_tmp.push_back(ch);
        }
    }
    m = m_tmp;
    //cout << m << endl;
    
    string answer("(None)");
    int play_time_max = 0;
    for(auto musicinfo : musicinfos){
        musicinfo += ',';
        
        int start_time, end_time, play_time;
        string music_name, music_notes;
        
        int token_idx = 0;
        string token;
        for(auto ch : musicinfo){
            if(ch == ','){
                switch(token_idx++){
                    int hr, min;
                    case START_TIME:
                        hr = stoi(token.substr(0, 2));
                        min = stoi(token.substr(3, 2));
                        start_time = hr * 60 + min;
                        break;
                    case END_TIME:
                        hr = stoi(token.substr(0, 2));
                        min = stoi(token.substr(3, 2));
                        end_time = hr * 60 + min;
                        play_time = end_time - start_time;
                        break;
                    case MUSIC_NAME:
                        music_name = token;
                        break;
                    case MUSIC_NOTES:
                        music_notes = token;
                        break;
                }
                token.clear();
            }
            else{
                if(ch == '#'){
                    token.back() += 'a' - 'A';
                }
                else{
                    token += ch;
                }
            }
        }
        int repetition = play_time / music_notes.size() + (play_time % music_notes.size() > 0);
        string music_notes_extended;
        while(repetition--){
            music_notes_extended += music_notes;
        }
        music_notes_extended.resize(play_time); /* 1 */
        //cout << play_time << endl;
        //cout << music_notes_extended << endl;
        if(music_notes_extended.find(m) == string::npos) continue;
        if(play_time > play_time_max){
            play_time_max = play_time;
            answer = music_name;
        }
    }
    return answer;
}