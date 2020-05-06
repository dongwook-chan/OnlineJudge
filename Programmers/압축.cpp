#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> w_to_idx;
    for(int idx = 0; idx < 26; ++idx){
        string w(1, 'A' + idx);
        w_to_idx[w] = idx + 1;
    }
    int i = 0;
    int next_idx = 27;
    vector<int> answer;
    while(i < msg.size()){
        string w;
        for(w += msg[i++]; !w_to_idx.insert(make_pair(w, next_idx)).second; w += msg[i++]);
        --i;
        ++next_idx;
        w.pop_back();
        answer.push_back(w_to_idx[w]);
    }
    return answer;
}