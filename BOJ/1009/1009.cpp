#include <iostream>
#include <vector>

using namespace std;

vector<int> cycle_for_base[] = {
    {0},
    {1},
    {2, 4, 8, 6},
    {3, 9, 7, 1},
    {4, 6},
    {5},
    {6},
    {7, 9, 3, 1},
    {8, 4, 2, 6},
    {9, 1}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        cout << cycle_for_base[a % 10][(b - 1) % cycle_for_base[a % 10].size()] << '\n';
    }

    return 0;
}