/* 1. 자기 자신에 대한 곱셈을 두번 하면 세제곱이 아니라 네제곱! */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string in;
int scr[3] = { -1, -1, -1 };
char bns[3], opt[3];
int ans;

int solution(string dartResult) {
    int i = 0;
	for (auto ch : dartResult) {
		if ('0' <= ch && ch <= '9') {
			if (bns[i] != 0) {
				scr[++i] = ch - '0';
			}
			else {
				switch (scr[i]) {
				case  1: scr[i] = 10;		break;
				case -1: scr[i] = ch - '0'; break;
				}
			}
		}
		else {
			switch (ch) {
			case 'S': case 'D': case 'T':	bns[i] = ch; break;
			case '*': case '#':				opt[i] = ch; break;
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		switch (bns[i]) {
		case 'D': scr[i] *= scr[i];			 break;
		case 'T': scr[i] *= scr[i] * scr[i]; break;
		}

		switch (opt[i]) {
		case '*':
			if(i > 0)
				scr[i - 1] *= 2;
			scr[i] *= 2; break;
		case '#':
			scr[i] *= -1; break;
		}
	}

	for (auto s : scr)
		ans += s;
    return ans;
}