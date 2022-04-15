#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_SPACE_SIZE 4
#define EMPTY 0
#define SHARK 17
#define OOM(x, y) (!(0 <= (x) && (x) < 4 && 0 <= (y) && (y) < 4))
//#define DEBUG

using namespace std;

enum DIRECTION {UP = 1, UL, LEFT, LD, DOWN, DR, RIGHT, RU};
int dx[] = {EMPTY, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {EMPTY, 0, -1, -1, -1, 0, 1, 1, 1};
struct fish_info {
    int x, y;
    DIRECTION d;
};

void print_space(vector<vector<int>> &fish_no_at, vector<fish_info> &fish_info_for) {
#ifdef DEBUG
    for(int x = 0; x < 4; ++x) {
        for(int y = 0; y < 4; ++y) {
            cout << fish_no_at[x][y] << ' ';
            switch(fish_info_for[fish_no_at[x][y]].d) {
            case UP: cout << "UP"; break;
            case UL: cout << "UL"; break;
            case LEFT: cout << "LEFT"; break;
            case LD: cout << "LD"; break;
            case DOWN: cout << "DOWN"; break;
            case DR: cout << "DR"; break;
            case RIGHT: cout << "RIGHT"; break;
            case RU: cout << "RU"; break;
            }
            cout << '\t';
        }
        cout << endl;
    }
    cout << endl;
#endif
    ;
}

int max_eaten_fish_no_sum;
#ifdef DEBUG
    int ctr;
#endif
void bf(int dpt, int eaten_fish_no_sum, vector<vector<int>> fish_no_at, vector<fish_info> fish_info_for, vector<bool> is_eaten) {
    if(max_eaten_fish_no_sum == 136) return;
#ifdef DEBUG
    cout << "fish: " << eaten_fish_no_sum << ", " << ctr << ", " << dpt << endl;
#endif
    // 물고기는 번호가 작은 물고기부터 순서대로 이동한다.
    for(int fish_no = 1; fish_no < SHARK; ++fish_no) {
    #ifdef DEBUG
        ++ctr;
    #endif
        if(is_eaten[fish_no]) continue;
        print_space(fish_no_at, fish_info_for);

        int x = fish_info_for[fish_no].x;
        int y = fish_info_for[fish_no].y;
        int d = fish_info_for[fish_no].d;

        int nd;
        for(int _ = 0; _ < 8; ++_) {    // 각 물고기는 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전시킨다.
            nd = (d - 1 + _) % 8 + 1;   // NOTE: 틀림
            int nx = x + dx[nd];        // NOTE d가 아니라 nd
            int ny = y + dy[nd];

            if(OOM(nx, ny)) continue;   // 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다.
            if(fish_no_at[nx][ny] == SHARK) continue;

            if(fish_no_at[nx][ny] != EMPTY) {
                fish_info_for[fish_no_at[nx][ny]].x = x;
                fish_info_for[fish_no_at[nx][ny]].y = y;
            }
            fish_info_for[fish_no].x = nx;
            fish_info_for[fish_no].y = ny;
            fish_info_for[fish_no].d = (DIRECTION)nd;

            // 그 외의 경우에는 그 칸으로 이동을 한다. 
            // 물고기가 다른 물고기가 있는 칸으로 이동할 때는 서로의 위치를 바꾸는 방식으로 이동한다.
            swap(fish_no_at[x][y], fish_no_at[nx][ny]);

            goto next_fish;
        }
        // 만약, 이동할 수 있는 칸이 없으면 이동을 하지 않는다. 
        fish_info_for[fish_no].d = (DIRECTION)nd;
    next_fish:
        continue;
    }
    print_space(fish_no_at, fish_info_for);
#ifdef DEBUG
    cout << "shark: " << eaten_fish_no_sum << ", " << ctr << ", " << dpt << endl;
#endif

    // 물고기의 이동이 모두 끝나면 상어가 이동한다.
    // 상어는 방향에 있는 칸으로 이동할 수 있는데 
    int x = fish_info_for[SHARK].x;
    int y = fish_info_for[SHARK].y;
    int d = fish_info_for[SHARK].d;

    for(int _ = 1; _ < 4; ++_) {
    #ifdef DEBUG
        ++ctr;
    #endif

        int nx = x + dx[d] * _;
        int ny = y + dy[d] * _;

        if(OOM(nx, ny)) break;   // 
        if(fish_no_at[nx][ny] == EMPTY) continue;  // 물고기가 없는 칸으로는 이동할 수 없다. // TODO: ??

        vector<vector<int>> new_fish_no_at = fish_no_at;
        vector<fish_info> new_fish_info_for = fish_info_for;
        vector<bool> new_is_eaten = is_eaten;

        new_is_eaten[new_fish_no_at[nx][ny]] = true;    // 그 칸에 있는 물고기를 먹고, 
        new_fish_info_for[SHARK] = {nx, ny, new_fish_info_for[new_fish_no_at[nx][ny]].d};   //  그 물고기의 방향을 가지게 된다

        int eaten_fish_no = new_fish_no_at[nx][ny];
        new_fish_no_at[x][y] = EMPTY;   // NOTE: 틀림....
        new_fish_no_at[nx][ny] = SHARK;

        max_eaten_fish_no_sum = max(max_eaten_fish_no_sum, eaten_fish_no_sum + eaten_fish_no);

    #ifdef DEBUG
        cout << "shark: " << eaten_fish_no_sum << ", " << ctr << ", " << dpt << endl;
    #endif
        print_space(new_fish_no_at, new_fish_info_for);

        bf(d + 1, eaten_fish_no_sum + eaten_fish_no, new_fish_no_at, new_fish_info_for, new_is_eaten);   // 상어가 이동한 후에는 다시 물고기가 이동하며, 이후 이 과정이 계속해서 반복된다.
    }
    // 상어가 이동할 수 있는 칸이 없으면 공간에서 벗어나 집으로 간다.
}

int main() {
    vector<vector<int>> fish_no_at(MAX_SPACE_SIZE, vector<int>(MAX_SPACE_SIZE));
    vector<fish_info> fish_info_for(SHARK + 1);
    vector<bool> is_eaten (SHARK, false);

    for(int x = 0; x < 4; ++x) {
        for(int y = 0; y < 4; ++y) {
            int fish_no, d;
            cin >> fish_no >> d;
            fish_no_at[x][y] = fish_no;
            fish_info_for[fish_no] = {x, y, (DIRECTION)d};
        }
    }

    is_eaten[fish_no_at[0][0]] = true;  // 청소년 상어는 (0, 0)에 있는 물고기를 먹고
    fish_info_for[SHARK] = {0, 0, fish_info_for[fish_no_at[0][0]].d};   // (0, 0)에 들어가게 된다. 상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다.
    
    fish_no_at[0][0] = SHARK;   // (0, 0)에 들어가게 된다.

    bf(0, 0, fish_no_at, fish_info_for, is_eaten);

    cout << max_eaten_fish_no_sum;

    return 0;
}