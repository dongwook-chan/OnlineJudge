// 6의 개수가 3개 (x) 연속된 6의 개수가 4개 (o)
#include <iostream>
using namespace  std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 0, N;
    cin >> N;
    int title;
    for(title = 1; n < N; ++title){
        int ctr = 0;
        for(int tmp_title = title; tmp_title; tmp_title /= 10){
            if(tmp_title % 10 == 6){
                if(++ctr >= 3){
                    ++n;
                    break;
                }
            }
            else{
                ctr = 0;
            }
        }
    }
    cout << title - 1;
    return 0;
}