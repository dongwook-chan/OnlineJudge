#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// split each string into 2-letter words (key) and count their frequency (value) in each string
void string_to_map(string &str, unordered_map<string, int> &map){
    for(int i = 0; i < str.size() - 1; ++i){
        string word = str.substr(i, i + 1);
        if(!map.insert(make_pair(word, 1))){
            ++map[word];
        }
    }
}

int jaccard(unordered_map<string, int> &map1, unordered_map<string, int> &map2){
    // collect all words in map1 and map2 // for any word that occurs, compare the occur
    unordered_map<string, int> intersection, merge;
    for(auto item1 : map1){
        auto item2 = map2.find(item1.first);
        if(item2 != map2.end()){
            item2->first
        }
    }
}

int solution(string str1, string str2) {
    unordered_map<string, int> map1, map2;
    string_to_map(str1, map1);
    string_to_map(str2, map2);
    return jaccard(map1, map2);
}