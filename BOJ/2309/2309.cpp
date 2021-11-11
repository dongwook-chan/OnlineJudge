#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int height_of_dwarf[9];
int dwarves[9];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int dwarf = 0; dwarf < 9; ++dwarf) {
        cin >> height_of_dwarf[dwarf];
    }

    int sum = accumulate(height_of_dwarf, height_of_dwarf + 9, 0);

    int fake_dwarf1, fake_dwarf2;
    for (fake_dwarf1 = 0; fake_dwarf1 < 8; ++fake_dwarf1) {
        for(fake_dwarf2 = fake_dwarf1 + 1; fake_dwarf2 < 9; ++fake_dwarf2) {
            if (sum - height_of_dwarf[fake_dwarf1] - height_of_dwarf[fake_dwarf2] == 100) {
                goto end;          
            }
        }
    }

end:
    iota (dwarves, dwarves + 9, 0);
    sort (dwarves, dwarves + 9, [](int const &dwarf1, int const &dwarf2) -> bool const {
        return height_of_dwarf[dwarf1] < height_of_dwarf[dwarf2];
    });

    for (int rank = 0; rank < 9; ++rank) {
        int dwarf = dwarves[rank];
        if (dwarf == fake_dwarf1 || dwarf == fake_dwarf2) continue;
        cout << height_of_dwarf[dwarf] << '\n';
    }
    
    return 0;
}