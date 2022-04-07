#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> lines;
    
    string line = string(N, '*') + string((N - 1) * 2 - 1, ' ') + string(N, '*');
    lines.push_back(line);

    // 중간 줄을 제외한 line 생성
    for(int i = 1; i < N - 1; ++i) {
        string line;
        // 좌측 공백
        line += string(i, ' ');
        // 좌측 X 날개
        line += '*' + string(N - 2, ' ') + '*';
        // 중간 공백
        line += string((N - 1) * 2 - 1 - i * 2, ' ');
        // 우측 X 날개
        line += '*' + string(N - 2, ' ') + '*';

        lines.push_back(line);
    }
    // 중간 line 생성
    string mid_line = string(N - 1, ' ') + '*' + string(N - 2, ' ') + '*' + string(N - 2, ' ') + '*';

    // 상부 line 출력
    for(string line : lines) {
        cout << line << '\n';
    }

    // 중간 line 출력
    cout << mid_line << '\n';

    // 하부 line 출력
    for(auto it = lines.rbegin(); it != lines.rend(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}