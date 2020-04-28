/*
    1. substr 문법 실수
    2. 다중집합의 크기는 삽입 여부와 관계 없이 증가해야 -> if문 밖으로
    3. 두 다중집합의 크기가 모두 0일 경우, J(A, B) = 1이다. 하지만 solution의 반환은 65536를 곱해야 한다.
    TC3 -> 0.19ms 3.98MB
*/

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// split each string into 2-letter words (key) and count their frequency (value) in each string
int string_to_map(string &str, unordered_map<string, int> &map){
    int size = 0;
    for(int i = 0; i < str.size() - 1; ++i){
        if(!isalpha(str[i]) || !isalpha(str[i + 1])) continue;
        ++size;                                                         /* 2 */
        string word = str.substr(i, 2);                                 /* 1 */
        if(!map.insert(make_pair(word, 1)).second){
            ++map[word];
        }
    }
    return size;
}

int intersect(unordered_map<string, int> &map1, unordered_map<string, int> &map2){
    int intersection = 0;
    for(auto item1 : map1){
        string word = item1.first;
        int freq1 = item1.second;
        auto item2 = map2.find(word);
        if(item2 != map2.end()){
            int freq2 = item2->second;
            intersection += min(freq1, freq2);
        }
    }
    return intersection;
}

int solution(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    unordered_map<string, int> map1, map2;
    int size1 = string_to_map(str1, map1);
    int size2 = string_to_map(str2, map2);
    if(size1 == 0 && size2 == 0) return 65536;      /* 3 */
    int sum = size1 + size2;
    int intersection = intersect(map1, map2);
    int merge = sum - intersection;
    return intersection * 65536 / merge;
}