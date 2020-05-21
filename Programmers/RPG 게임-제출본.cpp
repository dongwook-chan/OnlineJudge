#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int postorder_traversal(int skill_no, int &max_skill_no, vector<int> children[], vector<int> &answer, int &total_skill_ctr){
    int skill_ctr = children[skill_no].empty();
    for(auto child : children[skill_no]){
        skill_ctr += postorder_traversal(child, max_skill_no, children, answer, total_skill_ctr);
    }
    max_skill_no = max(max_skill_no, skill_no);
    answer[skill_no - 1] = skill_ctr;
    total_skill_ctr += skill_ctr;
    return skill_ctr;
}

int find_root(int parent[], int skill_no){
    if(!parent[skill_no]) return skill_no;
    return find_root(parent, parent[skill_no]);
}

vector<int> solution(int total_sp, vector<vector<int>> skills) {
    int parents[100001] = {0};
    vector<int> children[100001];
    for(auto skill : skills){
        int parent = skill[0];
        int child = skill[1];
        parents[child] = parent;
        children[parent].push_back(child);
    }
    int root = find_root(parents, skills[0][0]);
    int max_skill_no = 0;
    vector<int> answer(100001);
    int total_skill_ctr = 0;
    postorder_traversal(root, max_skill_no, children, answer, total_skill_ctr);

    int coef = total_sp / total_skill_ctr;
    answer.resize(max_skill_no);
    for(auto &sp : answer){
        sp *= coef;
    }
    return answer;
}
