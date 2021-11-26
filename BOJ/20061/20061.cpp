#include <iostream>
#include <algorithm>
#include <vector>

//#define DEBUG

using namespace std;

int N;

bool green_brd[6][4];
bool blue_brd[4][6];

struct point {
    int x;
    int y;
};

vector<point> blk_for_t[] = {
    {},
    { {0, 0} },
    { {0, 0}, {0, 1} },
    { {0, 0}, {1, 0} }
};

int score;
int sq_ctr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while (N--) {
#ifdef DEBUG
        cout << N << endl;
#endif
        int t, x, y;
        cin >> t >> x >> y;
        //cout << t << x << y << endl;

        vector<point> blk = blk_for_t[t];

        // green brd
#ifdef DEBUG
        cout << "green" << endl;
#endif
        // examine destination position
        int dst_x = 5;
        for (int x_ = 0; x_ < 6; ++x_) {
            for (point p : blk) {
                int nx = x_ + p.x;
                int ny = y + p.y;
                if (!(0 <= nx && nx < 6 && 0 <= ny && ny < 4)) goto end0;
                if (green_brd[nx][ny]) goto end0;
            }
            continue;
        end0:
            dst_x = min(dst_x, x_ - 1);
        }
        //cout << dst_x << endl;

        // place the block on the brds and update max
        for (point p : blk) {
            green_brd[dst_x + p.x][y + p.y] = true;
        }

#ifdef DEBUG
        for (int x_ = 0; x_ < 6; ++x_) {
            for (int y_ = 0; y_ < 4; ++y_) {
                cout << green_brd[x_][y_];
            }
            cout << endl;
        }
        cout << endl;       
#endif

        // if full row/column, erase the row/column and update max
        for (int x_ = 2; x_ < 6; ++x_) {
            for (int y_ = 0; y_ < 4; ++y_) {
                if (!green_brd[x_][y_]) goto end1;
            }
            ++score;
            for (int x__ = x_; x__ >= 2; --x__) {
                for (int y_ = 0; y_ < 4; ++y_) {
                    green_brd[x__][y_] = green_brd[x__ - 1][y_];
                }
            }
        end1:
            continue;
        }

#ifdef DEBUG        
        for (int x_ = 0; x_ < 6; ++x_) {
            for (int y_ = 0; y_ < 4; ++y_) {
                cout << green_brd[x_][y_];
            }
            cout << endl;
        }
        cout << endl;
#endif

        // if block on light brd, erase brd and update max
        int gap_x = 0;
        for (int x_ = 0; x_ < 2; ++x_) {
            for (int y_ = 0; y_ < 4; ++y_) {
                if (green_brd[x_][y_]) {
                    ++gap_x;
                    break;
                }
            }
        }

        for (int x_ = 5; x_ >= 2; --x_) {
            for (int y_ = 0; y_ < 4; ++y_) {
                green_brd[x_][y_] = green_brd[x_ - gap_x][y_];
            }
        }       

        /* 틀린 부분 */
        for (int x_ = 0; x_ < 2; ++x_) {
            for (int y_ = 0; y_ < 4; ++y_) {
                green_brd[x_][y_] = false;
            }
        }

#ifdef DEBUG
        for (int x_ = 0; x_ < 6; ++x_) {
            for (int y_ = 0; y_ < 4; ++y_) {
                cout << green_brd[x_][y_];
            }
            cout << endl;
        }
        cout << endl;
#endif

        // blue brd
#ifdef DEBUG
        cout << "blue" << endl;
#endif
        // examine destination position
        int dst_y = 5;
        for (int y_ = 0; y_ < 6; ++y_) {
            for (point p : blk) {
                int nx = x + p.x;
                int ny = y_ + p.y;
                if (!(0 <= nx && nx < 4 && 0 <= ny && ny < 6)) goto end2;
                if (blue_brd[nx][ny]) goto end2;
            }
            continue;
        end2:
            dst_y = min(dst_y, y_ - 1);
        }

        // place the block on the brds and update max
        for (point p : blk) {
            blue_brd[x + p.x][dst_y + p.y] = true;
        }       

#ifdef DEBUG
        for (int x_ = 0; x_ < 4; ++x_) {
            for (int y_ = 0; y_ < 6; ++y_) {
                cout << blue_brd[x_][y_];
            }
            cout << endl;
        }
        cout << endl;
#endif

        // if full row/column, erase the row/column and update max
        for (int y_ = 2; y_ < 6; ++y_) {
            for (int x_ = 0; x_ < 4; ++x_) {
                if (!blue_brd[x_][y_]) goto end3;
            }
            ++score;
            for (int y__ = y_; y__ >= 2; --y__) {
                for (int x_ = 0; x_ < 4; ++x_) {
                    blue_brd[x_][y__] = blue_brd[x_][y__ - 1];
                }
            }
        end3:
            continue;
        }

#ifdef DEBUG
        for (int x_ = 0; x_ < 4; ++x_) {
            for (int y_ = 0; y_ < 6; ++y_) {
                cout << blue_brd[x_][y_];
            }
            cout << endl;
        }
        cout << endl;
#endif

        // if block on light brd, erase brd and update max
        int gap_y = 0;
        for (int y_ = 0; y_ < 2; ++y_) {
            for (int x_ = 0; x_ < 4; ++x_) {
                if (blue_brd[x_][y_]) {
                    ++gap_y;
                    break;
                }
            }
        }

        for (int y_ = 5; y_ >= 2; --y_) {
            for (int x_ = 0; x_ < 4; ++x_) {
                blue_brd[x_][y_] = blue_brd[x_][y_ - gap_y];
            }
        }       

        /* 틀린 부분 */
        for (int y_ = 0; y_ < 2; ++y_) {
            for (int x_ = 0; x_ < 4; ++x_) {
                blue_brd[x_][y_] = false;
            }
        }

#ifdef DEBUG
        for (int x_ = 0; x_ < 4; ++x_) {
            for (int y_ = 0; y_ < 6; ++y_) {
                cout << blue_brd[x_][y_];
            }
            cout << endl;
        }
        cout << endl;
#endif
    }

    // green
    for (int x = 2; x < 6; ++x) {
        for (int y = 0; y < 4; ++ y) {
            if (green_brd[x][y]) ++sq_ctr;
        }
    }

    // blue
    for (int y = 2; y < 6; ++y) {
        for (int x = 0; x < 4; ++ x) {
            if (blue_brd[x][y]) ++sq_ctr;
        }
    }

    cout << score << '\n' << sq_ctr;

    return 0;
}