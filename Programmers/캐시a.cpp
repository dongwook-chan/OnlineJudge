/* 1. 캐시가 다 차기 전, 최초 캐싱 때도 hit이 발생할 수 있다! -> 최초 캐싱 부분을 따로 만들지 말고 최초가 아닌 부분과 동일한 규칙을 적용할 것 */

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

list<string> cache;
int t;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) {
		return cities.size() * 5;
	}
    
    for(auto&& city : cities){
        for(auto&& ch : city)
            if ('A' <= ch && ch <= 'Z')
				ch += 'a' - 'A';
    }

    /* 1 */
	for (int i = 0; i < cities.size(); ++i) {
		auto it = find(cache.begin(), cache.end(), cities[i]);
		if (it != cache.end()) {	// cache hit
			++t;

			cache.erase(it);
			cache.push_back(cities[i]);
		}
		else {	// cache miss
			t += 5;

            if(cache.size() == cacheSize)
			    cache.erase(cache.begin());
			cache.push_back(cities[i]);
		}
	}

	return t;
}