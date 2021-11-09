#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int *card_ctr_natural = new int[20000001];
    int *card_ctr = card_ctr_natural + 10000000;
  
    while(N--){
        int card;
        cin >> card;
        ++card_ctr_natural[card];
    }

    int M;
    cin >> M;
    while(M--){
        int card;
        cin >> card;
        cout << card_ctr_natural[card] << ' ';
    }

    return 0;
}