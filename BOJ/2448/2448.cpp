#include <iostream>

#define MAX_SIZE 3072

using namespace std;

int N;

bool grid[MAX_SIZE][MAX_SIZE * 2];

struct point {
    int y, x;
} base_case[] = {
                    {0, 2},
                {1, 1}, {1, 3},
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}
};

void recursive(int s, int y, int x) {
    if (s == 3) {
        for (point p : base_case) {
            grid[y + p.y][x + p.x] = true;
        }
        return;
    }

    int new_s = s / 2;
    recursive(new_s, y        , x + new_s * 1);
    recursive(new_s, y + new_s, x            ); 
    recursive(new_s, y + new_s, x + new_s * 2);
}

void print_grid() {
    int max_x = 2 * N;
    for(int y = 0; y < N; ++y) {
        for (int x = 0; x < max_x; ++x) {
            if (grid[y][x]) cout << '*';
            else            cout << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin >> N;

    recursive(N, 0, 0);
    print_grid();

    return 0;
}