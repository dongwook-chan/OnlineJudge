/* postfix increment operatro 사용 오류 */ 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crew_timetable;
    for(auto time : timetable){
        int crew_arrival_min = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        crew_timetable.push_back(crew_arrival_min);
    }
    sort(crew_timetable.begin(), crew_timetable.end());
    int crew_idx = 0;
    int bus_arrival_min = 9 * 60;
    for (int n_ = 0; n_ < n - 1; ++n_){  // per each bus
        for(int m_ = 0; m_ < m; ++m_){      // per each seat
            if(crew_timetable[crew_idx] > bus_arrival_min){
                break;
            }
            else{
                ++crew_idx;
            }
        }
        bus_arrival_min += t;
    }
    int bus_size = 0;
    int crew_last;
    for(int m_ = 0; m_ < m; ++m_){
        if(crew_timetable[crew_idx] > bus_arrival_min){
            break;
        }
        else{
            crew_last = crew_timetable[crew_idx];
            ++crew_idx;
            ++bus_size;
        }
    }
    // 마지막 버스에 빈칸 있으면 그 버스가 도착하는 시간
    int con_min;
    if(bus_size < m){
        con_min = bus_arrival_min;
    }
    // 마지막 버스에 빈칸이 없으면 그버스에 마지막으로 탑승하는 사람보다 먼저
    else{
        con_min = crew_last - 1;
    }
    string answer_hour = "0" + to_string(con_min / 60);
    string answer_min = "0" + to_string(con_min % 60);
    string answer = answer_hour.substr(answer_hour.size() - 2, 2) + ':' + answer_min.substr(answer_min.size() - 2, 2);
    return answer;
}