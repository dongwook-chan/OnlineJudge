#include <iostream>
#include <algorithm>
#include <iomanip>

#define MAX_OFFSET 5000
#define MAX_SIZE (MAX_OFFSET * 2 + 1)

using namespace std;

int grid_[MAX_SIZE][MAX_SIZE];
int *grid[MAX_SIZE];
int r1, c1, r2, c2;
int max_ctr;
struct diff {
    int dr, dc;
} directions[] = {
    // ↑        ←       ↓       →
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

void create_grid() {
    for (int r = -MAX_OFFSET; r < MAX_OFFSET; ++r) {
        grid[r] = grid_[r + MAX_OFFSET] + MAX_OFFSET;
    }
}

void fill_grid() {
    int ctr = 1;
    grid[0][0] = ctr++;
    for (int swirl = 0; swirl < 5; ++swirl) {
        int r = swirl;
        int c = swirl;

        int side = swirl * 2;

        for(diff direction : directions) {
            for(int i = 0; i < side; ++i) {
                r += direction.dr;
                c += direction.dc;

                grid[r][c] = ctr++;
            }
        }
    }
}

void find_widest() {
    for(int r = r1; r <= r2; ++r) {
        for(int c = c1; c <= c2; ++c) {
            max_ctr = max(max_ctr, grid[r][c]);
        }
    }
}

void print_grid() {
    for(int r = r1; r <= r2; ++r) {
        for(int c = c1; c <= c2; ++c) {
            cout << setfill(' ') << setw(to_string(max_ctr).size()) << grid[r][c] << ' ';
        }
        cout << '\n';
    }
}

void print_grid_all() {
    for(int r = -MAX_OFFSET; r <= MAX_OFFSET; ++r) {
        for(int c = -MAX_OFFSET; c <= MAX_OFFSET; ++c) {
            cout << grid[r][c] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    create_grid();

    cin >> r1 >> c1 >> r2 >> c2;

    //print_grid_all();

    fill_grid();

    find_widest();

    print_grid();

    return 0;
}