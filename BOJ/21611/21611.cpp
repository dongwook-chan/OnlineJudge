#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int grid[50][50];
struct point { int x, y; };
point shark; 
// X, ↑, ↓, ←, →
int dest_dy[] = {0, -1, 1, 0, 0};
int dest_dx[] = {0, 0, 0, -1, 1};
// ←, ↓, →, ↑
int move_dy[] = {0, 1, 0, -1};
int move_dx[] = {-1, 0, 1, 0};

int tmp[2500];
int new_tmp[5000];  // FIXED: '만약, 구슬이 칸의 수보다 많아 칸에 들어가지 못하는 경우 그러한 구슬은 사라진다.' -> 주어진 구슬 개수를 넘어설 수 있으니 배열 크기 넉넉하게

//#define DEBUG

void print_grid() {
#ifdef DEBUG
    cout << "print grid" << endl;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            cout << grid[y][x] << ' ';
        }
        cout << endl;
    }
#endif
}

void print_(int *tmp, int i) {
#ifdef DEBUG
    cout << "print tmp" << endl;
    for (int ii = 0; ii < i; ++ii) {
        cout << tmp[ii];
    }
    cout << endl;
#endif
}

void copy_to_tmp(int y, int x, int &i) {
    tmp[i++] = grid[y][x];

}
void copy_from_new_tmp(int y, int x, int &i) {
    grid[y][x] = new_tmp[i++];
}

void traverse(void (*do_for_pos)(int, int, int &), int &i) {
    int y = shark.y;
    int x = shark.x;
    i = 0;
    for (int r = 0; r < N / 2; ++r) {
        for (int d = 0; d < 4; ++d) {
#ifdef DEBUG
            cout << "d: " << d << ", _: " << (r * 2 + d / 2 + 1) << endl;
#endif
            for (int _ = 0; _ < r * 2 + d / 2 + 1; ++_) {
                y += move_dy[d];
                x += move_dx[d];
                do_for_pos(y, x, i);        // FIXED argument 순서를 parameter에 맞게 맞추기
#ifdef DEBUG
            //cout << grid[y][x] << " ";
            //print_(tmp, i);
#endif
            }
#ifdef DEBUG
            cout << endl;
#endif
        }
    }
    // extra round
    int d = 0;
    for (int _ = 0; _ < (N / 2 - 1) * 2 + 2; ++_) {
        y += move_dy[d];
        x += move_dx[d];
        do_for_pos(y, x, i);        // FIXED argument 순서를 parameter에 맞게 맞추기
#ifdef DEBUG
        //cout << grid[y][x] << " ";
        //print_(tmp, i);
#endif
    }
#ifdef DEBUG
    cout << endl;
#endif
}
int score_for_beed[] = {0, 1, 2, 3};
int score;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            cin >> grid[y][x];
        }
    }
    print_grid();

    shark = { (N + 1) / 2, (N + 1) / 2 };   // FIXED: shark 위치 공식 틀림! 본문에서 복붙하기! 
    while (M--) {
        int d, s;
        cin >> d >> s;

        // 구슬 파괴
#ifdef DEBUG
        cout << "구슬 파괴(d: " << d << ", s: " << s << ")" <<  endl;
#endif
        for (int ss = 1; ss <= s; ++ss) {
            int ny = shark.y + dest_dy[d] * ss;
            int nx = shark.x + dest_dx[d] * ss;
            grid[ny][nx] = 0;
        }
        print_grid();

        int i;
        traverse(copy_to_tmp, i);
#ifdef DEBUG
        cout << "i: " <<  i <<  endl;
#endif
        print_(tmp, i);

        int shift = 0;
        int ii;
        for (ii = 0; ii < i; ++ii) {
            if (!tmp[ii]) ++shift;
            else tmp[ii - shift] = tmp[ii]; 
        }
        for (; ii - shift < i; ++ii) {      // FIXED: 남은 칸들을 0으로 채워주기
            tmp[ii - shift] = 0;
        }
        print_(tmp, i);
        
        // 구슬 폭발
#ifdef DEBUG
        cout << "구슬 폭발" << endl;
#endif
        while (true) {
            int prev_tile = tmp[0];         // FIXED: 없는 -1번째 0구슬을 넣지 말고 (x) 0번째 tmp[0] 구슬 넣기
            int cont_ctr = 1;
            shift = 0;
            int ii;
            for (ii = 1; ii < i && tmp[ii]; ++ii) {
                if (prev_tile == tmp[ii]) {
                    ++cont_ctr;
                }
                else {
                    if (cont_ctr >= 4) {
                        shift += cont_ctr;
                        score += score_for_beed[prev_tile] * cont_ctr;
                    }
                    cont_ctr = 1;
                }
                tmp[ii - shift] = tmp[ii];      // FIXED: 연속된 구슬일 경우에도 연속 수가 4개 넘지 않을 수 있기 때문에, 매번 기록해줘야
                prev_tile = tmp[ii];
            }   
            if (cont_ctr >= 4) {                // FIXED: 마지막 원소는 다음 원소가 없어서 비교 대상 없음 -> loop 밖에서 마지막 연속 구슬 처리
                shift += cont_ctr;
                score += score_for_beed[prev_tile] * cont_ctr;
            }
            for (; ii - shift < i; ++ii) {      // FIXED: 남은 칸들을 0으로 채워주기
                tmp[ii - shift] = 0;
            }
            print_(tmp, i);
            if (!shift) break;
        }

        // 구슬 변화
#ifdef DEBUG
        cout << "구슬 변화" << endl;
#endif
        memset(new_tmp, 0, sizeof(new_tmp));    // FIXED: new_tmp는 매번 다른 개수의 원소가 채워짐 -> 이전 시전의 원소들이 매번 초기화되어야
        int new_i = 0;
        int prev_tile = tmp[0];
        int cont_ctr = 1;
        for (int ii = 1; ii < i; ++ii) {
            if (prev_tile == tmp[ii]) {
                ++cont_ctr;
            }
            else {
                new_tmp[new_i++] = cont_ctr;
                new_tmp[new_i++] = prev_tile;
                cont_ctr = 1;
            }
            prev_tile = tmp[ii];
        }
        new_tmp[new_i++] = cont_ctr;    // FIXED: 마지막 원소는 다음 원소가 없어서 비교 대상 없음 -> loop 밖에서 마지막 연속 구슬 처리
        new_tmp[new_i++] = prev_tile;
        print_(new_tmp, i);

        traverse(copy_from_new_tmp, new_i);
        print_grid();
    }

    cout << score;

    return 0;
}