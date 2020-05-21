/*
    현재 선택된 열집합의 부분집합이 과거에 선택됐다면 최소성 불만족으로 후보키가 될 수 없다
    1. 브루트포스로 돌면 선택된 (1, 2, 3)을 (2, 3)이 선택된 후에 배제하는(최소x) 로직 필요
    2. 브루트포스 후 선택된 모든 키에 대해서 부분집합 검사
    
    어떤 키의 조합을 골랐는지 확인해야! 킷값의 조합이 아님    
    
    합쳐져서 같아질 수 있는 경우 대비 위해 결합 위치에 '.' 붙이기
    concat_key = "abc" + "def"; -> concat_key = "abc" + '.' + "def";
    concat_key = "ab" + "bdef"; -> concat_key = "ab" + '.' + "cdef";
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

enum CMD {CHECK, PUSH};
struct qnode{
    int bm;
    int c;
    int cmd;
};

bool vst[256];
int answer;
int solution(vector<vector<string>> relation) {
    queue<qnode> q;
    q.push({0, 0, CHECK});
    vst[0] = true;
    
    int R = relation.size();
    int C = relation[0].size();
    
    while(q.size()){
        int bm = q.front().bm;
        int c = q.front().c;
        bool cmd = q.front().cmd;
        
        unordered_set<string> candidate_keys;
        candidate_keys.insert(string());
        switch(cmd){
            case CHECK:
                for(int r = 0; r < R; ++r){
                    string concat_keys;
                    for(int c = 0, b = 1; b < (1 << C); ++c, b <<= 1){
                        if(bm && b){
                            concat_keys += '.' + relation[r][c];
                        }
                    }
                    if(!candidate_keys.insert(concat_keys).second) goto select_more_columns;
                }
                ++answer;
                for(int i = bm; i < (1 << C); ++i){
                    if((i & bm) == bm){
                        vst[i] = true;
                    }
                }
                continue;
            select_more_columns:
                q.push({bm, c, PUSH});
                break;
            case PUSH:
                for(; c < C; ++c){
                    if(vst[bm | 1 << c]) continue;
                    vst[bm | 1 << c] = true;
                    q.push({bm | (1 << c), c + 1, CHECK});
                }
                break;
        }
    }
    return answer;
}

int main(){
    vector<vector<string>> relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    solution(relation);
    return 0;
}