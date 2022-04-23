#include <iostream>
#include <cstring>

#define MAX_ARRAY_SIZE 50

using namespace std;

int N, M;
string before[MAX_ARRAY_SIZE];
string after[MAX_ARRAY_SIZE];

int ctr;

void flip(int y, int x) {
    for(int dy = 0; dy < 3; ++dy) {
        for(int dx = 0; dx < 3; ++dx) {
            before[y + dy][x + dx] = 1 - (before[y + dy][x + dx] - '0') + '0';
        }
    }
    ++ctr;
}

int main(){
    cin >> N >> M;

    for(int y = 0; y < N; ++y) {
        cin >> before[y];
    }

    for(int y = 0; y < N; ++y) {
        cin >> after[y];
    }

    for(int y = 0; y < N - 2; ++y) {
        for(int x = 0; x < M - 2; ++x) {
            if(before[y][x] != after[y][x]) {
                flip(y, x);
            }
        }
    }

    for(int y = 0; y < N; ++y) {
        for(int x = 0; x < N; ++x) {
            if(before[y][x] != after[y][x]) {
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << ctr;
    return 0;
}