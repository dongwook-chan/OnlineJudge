#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>

#define MAX_FREQ_SIZE 8000
#define MID_FREQ_INDEX 4000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int *inputs = new int[N];
    int freq_natural[MAX_FREQ_SIZE + 1] = {0};
    int *freq_integer = freq_natural + MID_FREQ_INDEX;

    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;

        inputs[i] = input;
        ++freq_integer[input];
    }

    int average = round((double) accumulate(inputs, inputs + N, 0) / N);

    nth_element(inputs, inputs + N / 2, inputs + N);
    int median = inputs[N / 2];

    int max_freq = *max_element(freq_integer - MID_FREQ_INDEX, freq_integer + MID_FREQ_INDEX + 1);

    vector<int> max_freq_inputs;
    for (int input = -MID_FREQ_INDEX; input <= MID_FREQ_INDEX; ++input) {
        if (freq_integer[input] == max_freq) {
            max_freq_inputs.push_back(input);
        }
    }

    int mode;
    if (max_freq_inputs.size() == 1) {
        mode = max_freq_inputs.front();
    }
    else {
        nth_element(max_freq_inputs.begin(), max_freq_inputs.begin() + 1, max_freq_inputs.end());
        mode = max_freq_inputs[1];
    }

    int range = *max_element(inputs , inputs + N) - *min_element(inputs, inputs + N);

    cout << average << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0; 
}