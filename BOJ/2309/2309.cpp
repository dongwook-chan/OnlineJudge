#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int hgt_of_dwarf[9];
int hgt_of_real[7];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int dwarf = 0; dwarf < 9; ++dwarf) {
        cin >> hgt_of_dwarf[dwarf];
    }

    int hgt_sum_of_fakes = accumulate(hgt_of_dwarf, hgt_of_dwarf + 9, 0) - 100;

    int fake_hgt1, fake_hgt2;
    for (int fake1 = 0; fake1 < 8; ++fake1) {
        for(int fake2 = fake1 + 1; fake2 < 9; ++fake2) {
            if (hgt_of_dwarf[fake1] + hgt_of_dwarf[fake2] == hgt_sum_of_fakes) {
                fake_hgt1 = hgt_of_dwarf[fake1];
                fake_hgt2 = hgt_of_dwarf[fake2];
                goto end;
            }
        }
    }

end:
    sort (hgt_of_dwarf, hgt_of_dwarf + 9);

    for (int dwarf = 0; dwarf < 9; ++dwarf) {
        int hgt = hgt_of_dwarf[dwarf];
        if (hgt == fake_hgt1 || hgt == fake_hgt2) continue;
        cout << hgt << '\n';
    }
    
    return 0;
}