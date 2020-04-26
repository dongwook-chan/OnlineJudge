/* 1. alphabet을 제외한 문자를 제거하지 말고 애초에 받지 않으면 된다. */
/* 2. !alphabet도 입력 받아야 양 옆 문자와 조합해서 만든 key를 제외시킬 수 있다. */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string strA, strB;
unordered_map<string, int> setA, setB;
int set_sizeA, set_sizeB;

void preproc_str(string src, string &dst) {	/* 1 */
	for (auto ch : src) {
		if ('a' <= ch && ch <= 'z')
			dst += ch;
		else if ('A' <= ch && ch <= 'Z')
			dst += ch + ('a' - 'A');
		else	/* 2 */
			dst += '0';
	}
}

void str_to_set(string str, unordered_map<string, int> &set, int &set_size) {
	for (int i = 1; i < str.size(); ++i) {
		if (str[i - 1] == '0' || str[i] == '0') {	/* 2 */
			continue;
		}

		string key;
		key += str[i - 1];
		key += str[i];

		++set_size;
		if (set.find(key) != set.end()) {
			++set[key];
		}
		else {
			set[key] = 1;
		}
	}
}

int A_dif_B(unordered_map<string, int> setA, unordered_map<string, int> setB) {
	int dif = 0;
	for (auto elemA : setA) {
		auto elemB = setB.find(elemA.first);
		if (elemB != setB.end()) {	// match
			dif += max(0, elemA.second - (*elemB).second);
		}
		else {	// miss
			dif += elemA.second;
		}
	}
	return dif;
}

int solution(string str1, string str2) {
    preproc_str(str1, strA);
    preproc_str(str2, strB);
    
    str_to_set(strA, setA, set_sizeA);
	str_to_set(strB, setB, set_sizeB);

	int dif = A_dif_B(setA, setB);
	int itr = set_sizeA - dif;
	int un = set_sizeB + dif;
    
    if(un == 0) return 65536;
    else return (itr * 65536) / un;
}