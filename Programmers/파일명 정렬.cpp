#include <string>
#include <vector>
#include <locale>
#include <algorithm>

using namespace std;

vector<string> heads;
vector<int> numbers;

bool cmp(const int &a, const int &b){
    if(heads[a] == heads[b]){
        return numbers[a] < numbers[b];
    }
    return heads[a] < heads[b];
}

vector<string> solution(vector<string> files) {
    for(auto file : files){
        int i, j;
        for(i = 0; i < file.size() && !isdigit(file[i]); ++i);
        string head = file.substr(0, i);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        heads.push_back(head);
        for(j = i; j < file.size() && isdigit(file[j]); ++j);
        numbers.push_back(stoi(file.substr(i, j - i + 1)));
    }
    vector<int> indices;
    for(int i = 0; i < files.size(); ++i){
        indices.push_back(i);
    }
    stable_sort(indices.begin(), indices.end(), cmp);
    vector<string> answer;
    for(auto index : indices){
        answer.push_back(files[index]);
    }
    return answer;
}