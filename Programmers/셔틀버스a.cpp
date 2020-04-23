#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, t, m;
string crew_time;
vector<pair<int, int>> crew_times;
vector<pair<int, int>> bus_queue[10];

pair<int, int> add(pair<int, int> a, int b) {
	int min = a.second + b;
	return make_pair(a.first + min / 60, min % 60);
}

pair<int, int> sub1(pair<int, int> a) {
	if (a.second == 0)
		return make_pair(a.first - 1, 59);
	return make_pair(a.first, a.second - 1);
}

string solution(int n, int t, int m, vector<string> timetable) {
    for(auto crew_time : timetable){
        crew_times.emplace_back(10 * (crew_time[0] - '0') + crew_time[1] - '0', 10 * (crew_time[3] - '0') + crew_time[4] - '0');
    }
    
    sort(crew_times.begin(), crew_times.end());	// sort crew arrival time

	pair<int, int> bus_time = { 9, 0 };
	int next_crew = 0;
	for (int i = 0; i < n; ++i) {	// assign to time slot

		for (int j = 0; j < m; ++j) {	// assign up to m crews
			if (next_crew < crew_times.size() && crew_times[next_crew] <= bus_time)
				bus_queue[i].push_back(crew_times[next_crew++]);
			else
				break;
		}
		bus_time = add(bus_time, t);
	}

	pair<int, int> ans = { 9, 0 };
	if (bus_queue[n - 1].size() == m) {
		ans = sub1(bus_queue[n - 1][m - 1]);
	}
	else {
		ans = add(ans, (n - 1) * t);
	}
    string answer;
	answer += ans.first / 10 + '0';
    answer += ans.first % 10 + '0';
    answer += ':';
    answer += ans.second / 10 + '0';
    answer += ans.second % 10 + '0';
    return answer;
}