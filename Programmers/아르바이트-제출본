#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void select(vector<vector<int>> &last_days, vector<vector<int>> &salaries, int first_day, int max_first_day, int salary_sum, int &max_salary_sum) {
    max_salary_sum = max(max_salary_sum, salary_sum);
    if(first_day > max_first_day) return;
    int max_job_idx = last_days[first_day].size();
    for (int job_idx = 0; job_idx < max_job_idx; ++job_idx) {
        select(last_days, salaries, last_days[first_day][job_idx], max_first_day, salary_sum + salaries[first_day][job_idx], max_salary_sum);
    }
    select(last_days, salaries, first_day + 1, max_first_day, salary_sum, max_salary_sum);
}

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> part_times) {
    int max_first_day = (*max_element(part_times.begin(), part_times.end(), cmp))[0];
    vector<vector<int>> last_days(max_first_day + 1), salaries(max_first_day + 1);
    for(auto part_time : part_times){
        int first_day = part_time[0];
        int last_day = part_time[1];
        int salary = part_time[2];
        last_days[first_day].push_back(last_day);
        salaries[first_day].push_back(salary);
    }
    int answer = 0;
    select(last_days, salaries, 0, max_first_day, 0, answer);
    return answer;
}
