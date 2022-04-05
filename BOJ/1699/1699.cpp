/*
    제곱수 나열: 1, 4, 9, ...
    1 4개보다는 4 1개가 최소항 -> 3까지는 1로 만들고, 4부터는 4로 만들어야
    Greedy하게 N보다 작으면서 가장 큰 제곱수부터 채워나가면 될 듯?

    단, 작은 수 부터 탐색(bottom-up)해나가야 '가장 큰 제곱수' 늘려나갈 수 있다.
    큰 수부터 탐색하면(top-down) '가장 큰 제곱수'를 이진 탐색으로 찾아야 한다.
*/

#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_SIZE 100000

using namespace std;

int table[MAX_SIZE + 1];

int main() {
    int N;
    cin >> N;

    int square_ctr = 1;
    int square = 1;
    int next_square = 4;
    for(int n = 1; n <= N; ++n) {
        if(n == next_square) {
            ++square_ctr;
            square = square_ctr * square_ctr;
            next_square = (square_ctr + 1) * (square_ctr + 1);
        }
        int rem = n - square;
        table[n] = table[rem] + 1;
    }

    cout << table[N];

    return 0;
}