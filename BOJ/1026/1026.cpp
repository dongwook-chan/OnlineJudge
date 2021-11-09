#include <iostream>

using namespace std;

void set_array(short N, short *array){
    for(int _ = 0; _ < N; ++_){
        int input;
        cin >> input;
        ++array[input];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short N;
    cin >> N;
    
    short A[101] = {0};
    set_array(N, A);

    short B[101] = {0};
    set_array(N, B);

    short a = 0, b = 100;
    int sum = 0;
    for(int _ = 0; _ < N; ++_){
        // get next for A
        for(; a < 101; ++a){
            if (A[a]-- > 0) {
                break;
            }
        }
        
        // get next for B
        for (; b >= 0; --b){
            if (B[b]-- > 0) {
                break;
            }
        }
        sum += a * b;
    }

    cout << sum;
}