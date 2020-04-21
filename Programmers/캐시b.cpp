/* 1. cacheSize 0인경우 고려하기! */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(!cacheSize) return cities.size() * 5;    /* 1 */
    
    queue<string> cache;
    int answer = 0;
    for(auto &city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        // cache search
        bool cache_hit = false;
        int qs = cache.size();
        while(qs--){
            string item = cache.front();
            cache.pop();
            if(city != item){
                cache.push(item);
            }
            else{
                cache_hit = true;
            }
        }
        if(cache.size() >= cacheSize){
            cache.pop();
        }
        cache.push(city);
        if(cache_hit){
            ++answer;
        }
        else{
            answer += 5;
        }
    }
    return answer;
}