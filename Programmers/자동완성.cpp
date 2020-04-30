#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

struct trie {
    int child_size;
    bool visited;
    trie *childs[26];
};

bool cmp(const string &a, const string &b){
    return a.size() < b.size();
}

void insert(trie *root, string &word, int depth){
    if(depth >= word.size()){
        return;
    }
    char letter = word[depth];
    trie **child = root->childs + letter - 'a';
    if(*child == NULL){  // miss
        *child = (trie *)calloc(1, sizeof(trie));
    }
    ++root->child_size;
    insert(*child, word, depth + 1);
}

int answer = 0;
void select(trie *root, string &word, int depth){
    if(depth >= word.size()){
        //cout << word << ": " << depth << endl;
        answer += depth;
        root->visited = true;
        return;
    }
    char letter = word[depth];
    //cout << depth << ": " << root->child_size << ": " << letter << ", " << root->childs[letter - 'a'] << endl;
    if(root->child_size == 1){
        if(root->visited){
            select(root->childs[letter - 'a'], word, depth + 1);
        }
        else{
            //cout << word << ": " << depth << endl;
            answer += depth;
        }
    }
    else{
        select(root->childs[letter - 'a'], word, depth + 1);
    }
}

int solution(vector<string> words) {
    trie *root = (trie *)calloc(1, sizeof(trie));    
    sort(words.begin(), words.end(), cmp);
    for(auto word : words){
        insert(root, word, 0);
    }
    //cout << root->child_size << endl;
    for(auto word : words){
        //cout << word << endl;
        select(root, word, 0);
    }
    return answer;
}