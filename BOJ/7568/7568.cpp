#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int x[50] = {0};
    int y[50] = {0};
    for (int i = 0; i < N; ++i){
        cin >> x[i] >> y[i];
    }
    
    int rank[50];
    fill(rank, rank + N, 1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            
            if (x[j] > x[i] && y[j] > y[i]) {
                ++rank[i];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << rank[i] << ' ';
    }

    return 0;
}