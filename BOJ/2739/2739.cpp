#include <iostream>
#include <format>

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int i = 1; i <= 9; ++i) {
        cout << format("{} * {} = {}", N, i, N * i);
    }

    return 0;
}