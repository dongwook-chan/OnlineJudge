#include <iostream>
#include <vector>
#include <cstring>

#define MAX_MATCH_NO 15

using namespace std;

int input_score[4][6][3];
enum TEAM {A, B, C, D, E, F};
pair<TEAM, TEAM> teams_for_match[MAX_MATCH_NO] = {
    {A, B}, {A, C}, {A, D}, {A, E}, {A, F},
    {B, C}, {B, D}, {B, E}, {B, F},
    {C, D}, {C, E}, {C, F},
    {D, E}, {D, F},
    {E, F}
};
enum RESULT {WIN, TIE, LOSE};
int current_score[6][3];
bool case_possible[4];
vector<TEAM> team_to_compare_for_match[MAX_MATCH_NO + 1] = {
//   0   1   2   3   4   5    6   7   8   9   10  11   12  13   14      15
    {}, {}, {}, {}, {}, {A}, {}, {}, {}, {B}, {}, {}, {C}, {}, {D}, {E, F}
};

int ctr;
void bf(int match_no, int diff_ctr, vector<bool> diff_from_current_score) {  // NOTE: 전역 변수 undo가 어려운 경우 copy 후 자식에게 넘겨주기 
    if(!team_to_compare_for_match[match_no].empty()) {
        for(TEAM team : team_to_compare_for_match[match_no]) {
            for(int case_ = 0; case_ < 4; ++case_) {
                if(diff_from_current_score[case_]) continue;
                if(memcmp(current_score[team], input_score[case_][team], sizeof(int) * 3)) {
                    diff_from_current_score[case_] = true;
                    if(++diff_ctr == 4) return;
                }
            }
        }
    }
    if(match_no == 15) {
        for(int case_ = 0; case_ < 4; ++case_) {
            if(!memcmp(current_score, input_score[case_], sizeof(int) * 18)) {
                case_possible[case_] = true;
            }
        }
        return;  
    }

    pair<TEAM, TEAM> team = teams_for_match[match_no];
    // first team wins
    ++current_score[team.first][WIN];
    ++current_score[team.second][LOSE];
    bf(match_no + 1, diff_ctr, diff_from_current_score);
    --current_score[team.first][WIN];
    --current_score[team.second][LOSE];

    // tie
    ++current_score[team.first][TIE];
    ++current_score[team.second][TIE];
    bf(match_no + 1, diff_ctr, diff_from_current_score);
    --current_score[team.first][TIE];
    --current_score[team.second][TIE];

    // second team wins
    ++current_score[team.first][LOSE];
    ++current_score[team.second][WIN];
    bf(match_no + 1, diff_ctr, diff_from_current_score);
    --current_score[team.first][LOSE];
    --current_score[team.second][WIN];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int case_ = 0; case_ < 4; ++case_) {
        for(TEAM team : {A, B, C, D, E, F}) {
            for(RESULT result : {WIN, TIE, LOSE}) {
                cin >> input_score[case_][team][result];
            }
        }
    }
   
    bf(0, 0, vector<bool>(6, false));

    for(int case_ = 0; case_ < 4; ++case_) {
        cout << (int)case_possible[case_] << ' ';
    }

    return 0;
}