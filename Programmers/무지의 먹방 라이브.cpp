#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp_time(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}

bool cmp_idx(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;   
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int>> food_idx_times;
    for(int i = 0; i < food_times.size(); ++i) {
        food_idx_times.push_back(make_pair(food_times[i], i));
    }
    sort(food_idx_times.begin(), food_idx_times.end(), cmp_time);
    long long last_min = 0;
    while (food_idx_times.size() && k >= (food_idx_times.back().first - last_min) * food_idx_times.size()){
        k -= (food_idx_times.back().first - last_min) * food_idx_times.size();
        last_min = food_idx_times.back().first;
        food_idx_times.pop_back();
    }
    if(food_idx_times.empty()) return -1;
    sort(food_idx_times.begin(), food_idx_times.end(), cmp_idx);
    return food_idx_times[k % food_idx_times.size()].second + 1;
}