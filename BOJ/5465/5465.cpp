#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int N, S;
bool visited[800][800];
queue<pair<int, int>> bear_q, bee_q;
pair<int, int> dst;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    for(int r = 0 ;r < N; ++r){
        string row;
        cin >> row;
        for(int c = 0; c < N; ++c){
            switch(row[c]){
            case 'M':
            bear_q.push(make_pair(r, c));
            break;
            case 'D':
            dst = make_pair(r, c);
            break;
            case 'H':
            bee_q.push(make_pair(r, c));
            break;
            switch(row[c]){
            case 'T': case 'M': case 'H':
            visited[r][c] = true;
            break;
            }
        }
    }
    int bear_qs;
    while(bear_qs = bear_q.size()){
        while(bear_qs--){
            
        }
    }
    return 0;
}