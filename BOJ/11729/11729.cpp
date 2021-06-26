#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ctr;
string ret;

void F(int N, string order){
    if (N == 1){
        ++ctr;
        string line{order[0], ' ', order[2], '\n'};
        ret += line;
        return;
    }
    
    string new_order;

    new_order = order;
    swap(new_order[1], new_order[2]);
    F(N - 1, new_order);

    F(1, order);

    new_order = order;
    swap(new_order[0], new_order[1]);
    F(N - 1, new_order);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    F(N, "123");

    cout << ctr << '\n';
    cout << ret;

    return 0;
}