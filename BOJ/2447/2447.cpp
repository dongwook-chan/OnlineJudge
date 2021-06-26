#include <iostream>
#include <string>

using namespace std;

string pattern[6561];

void plot_pattern(int x, int y, int side, bool is_empty){
    if (side == 1){
        char tile = is_empty ? ' ' : '*';
        pattern[y].push_back(tile);
        return;
    }

    int new_side = side / 3;
    for(int dy = 0; dy < side; dy += new_side){
        for(int dx = 0; dx < side; dx += new_side){
            if(dy == new_side && dx == new_side){
                plot_pattern(x + dx, y + dy, new_side, true);
            }
            else{
                plot_pattern(x + dx, y + dy, new_side, is_empty | false);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    plot_pattern(0, 0, n, false);
    
    for(auto&& line : pattern){
        if (line.empty()) break;
        cout << line << '\n';
    }

    return 0;
}