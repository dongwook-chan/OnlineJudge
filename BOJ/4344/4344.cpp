#include <iostream>
#include <numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(3);
    cout.setf(ios::fixed, ios::floatfield);

    int C;
    cin >> C;
    int score[1000] = {0};
    while(C--){
        int N;
        cin >> N;

        for(int i = 0; i < N; ++i){
            cin >> score[i];
        }

        int sum = accumulate(score, score + N, 0);
        float avg = (float) sum / N;

        int ctr = 0;
        for(int i = 0; i < N; ++i){
            if(score[i] > avg) ++ctr;
        }

        cout << left << (float) ctr / N * 100.0 << fixed << "%\n";
    }

    return 0;
}