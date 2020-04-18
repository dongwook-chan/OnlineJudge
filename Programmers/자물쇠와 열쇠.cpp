#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();
    
    int hole_ctr = 0;
    for(auto row : lock){
        for(auto pnt : row){
            if(!pnt){
                ++hole_ctr;
            }
        }
    }
    for(int dir = 0; dir < 4; ++dir){
        // 돌리기
        int rep_max = M / 2;
        int rotate_ofs = M - 1;
        for(int rep = 0; rep < rep_max; ++rep, rotate_ofs -= 2){
            int r = rep;
            int c = rep;
            int buf[80], b = 0;
            for(int _ = 0; _ < rotate_ofs; ++_) buf[b++] = key[r][c++];
            for(int _ = 0; _ < rotate_ofs; ++_) buf[b++] = key[r++][c];
            for(int _ = 0; _ < rotate_ofs; ++_) buf[b++] = key[r][c--];
            for(int _ = 0; _ < rotate_ofs; ++_) buf[b++] = key[r--][c];
            rotate(buf, buf + rotate_ofs, buf + b);
            r = c = rep;
            b = 0;
            for(int _ = 0; _ < rotate_ofs; ++_) key[r][c++] = buf[b++];
            for(int _ = 0; _ < rotate_ofs; ++_) key[r++][c] = buf[b++];
            for(int _ = 0; _ < rotate_ofs; ++_) key[r][c--] = buf[b++];
            for(int _ = 0; _ < rotate_ofs; ++_) key[r--][c] = buf[b++];
        }
        
        // 맞추기
        for(int key_rb = -M + 1; key_rb < N; ++key_rb){
            for(int key_cb = -M + 1; key_cb < N; ++key_cb){
                int blocked_ctr = 0;
                for(int key_r = 0; key_r < M; ++key_r){
                    for(int key_c = 0; key_c < M; ++key_c){
                        int lock_r = key_rb + key_r;
                        int lock_c = key_cb + key_c;
                        if(lock_r < 0 || N <= lock_r || lock_c < 0 || N <= lock_c) continue;        
                        if(key[key_r][key_c] && lock[lock_r][lock_c]) goto next_point;
                        if(!key[key_r][key_c] && !lock[lock_r][lock_c]) goto next_point;
                        if(key[key_r][key_c] && !lock[lock_r][lock_c]){
                            ++blocked_ctr;
                        }
                    }
                }
                if(blocked_ctr == hole_ctr) return true;
                next_point:
                    continue;
            }
        }
    }
    return false;
}
