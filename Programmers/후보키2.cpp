/*
    현재 선택된 열집합의 부분집합이 과거에 선택됐다면 최소성 불만족으로 후보키가 될 수 없다
    1. 브루트포스로 돌면 선택된 (1, 2, 3)을 (2, 3)이 선택된 후에 배제하는(최소x) 로직 필요
    2. 브루트포스 후 선택된 모든 키에 대해서 부분집합 검사
    
    어떤 키의 조합을 골랐는지 확인해야! 킷값의 조합이 아님    
    
    합쳐져서 같아질 수 있는 경우 대비 위해 결합 위치에 '.' 붙이기
    concat_key = "abc" + "def"; -> concat_key = "abc" + '.' + "def";
    concat_key = "ab" + "bdef"; -> concat_key = "ab" + '.' + "cdef";
*/

/*
    오답
    1. bfs할 때는 q.front() 추출 후 q.pop();
    2. bitwise는 &&, || 아니라 &, |
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

#include <iostream>

using namespace std;

struct qnode{
    int bm;
    int c;
};

int solution(vector<vector<string>> relation) {
    int R = relation.size();
    int C = relation[0].size();
    
    queue<qnode> q;
    q.push({0, 0});
    vector<int> vst;
    int answer = 0;
    unordered_set<string> candidate_keys;
    
    while(q.size()) {
        int bm = q.front().bm;
        int c = q.front().c;
        q.pop();    /* 1 */
        
        for(auto vst_bm : vst){
            if((vst_bm & bm) == vst_bm) goto next_selection;
        }
        
        candidate_keys.clear();
        candidate_keys.insert(string());
        for(int r = 0; r < R; ++r) {
            string concat_keys;
            for(int c = 0, b = 1; c < C; ++c, b <<= 1) {
                if(bm & b){     /* 2 */
                    concat_keys += '.' + relation[r][c];
                }
            }
            if(!candidate_keys.insert(concat_keys).second) goto select_more_columns;
        }
        ++answer;
        vst.push_back(bm);
        continue;
    select_more_columns:
        for(; c < C; ++c) {
            q.push({bm | (1 << c), c + 1});
        }
    next_selection:
        continue;
    }
    return answer;
}
