#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_NO 500

using namespace std;

int power_of_two[MAX_NO + 1];
int power_of_five[MAX_NO + 1];
int N;

int main() {
    int next_two = 4;
    int two_ctr = 1;
    for(int two = 2; two <= MAX_NO; two += 2) {
        if(two == next_two) {
            ++two_ctr;
            next_two *= 2;
        }
        power_of_two[two] = two_ctr;
    }

    int next_five = 25;
    int five_ctr = 1;
    for(int five = 5; five <= MAX_NO; five += 5) {
        if(five == next_five) {
            ++five_ctr;
            next_five *= 5;
        }
        power_of_five[five] = five_ctr;
    }

    cin >> N;

    int two_sum = 0;
    int five_sum = 0;
    for(int i = 0; i <= N; ++i) {
        two_sum += power_of_two[i];
        five_sum += power_of_five[i];
    }

    cout << min(two_sum, five_sum);

    return 0;
}