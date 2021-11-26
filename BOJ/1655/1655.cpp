#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    
    int N;
    cin >> N;

    int no;
    for (int no_ctr = 1; no_ctr <= N; ++no_ctr) {
        cin >> no;

        max_heap.push(no);
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        int min_heap_size = no_ctr / 2 + 1;
        
        if (min_heap.size() > min_heap_size) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        cout << min_heap.top() << '\n';
    }


    return 0;
}