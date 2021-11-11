#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int height_of_dwarf[9];
int height_of_real_dwarf[7];

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
    int real_dwarf = 0;
    for (int dwarf = 0; dwarf < 9; ++dwarf) {
        if (dwarf == fake_dwarf1 || dwarf == fake_dwarf2) continue;
        height_of_real_dwarf[real_dwarf++] = height_of_dwarf[dwarf];
    }

    sort(height_of_real_dwarf, height_of_real_dwarf + 7);

    for (int real_dwarf = 0; real_dwarf < 7; ++real_dwarf) {
        cout << height_of_real_dwarf[real_dwarf] << '\n';
    }
    
    return 0;
}