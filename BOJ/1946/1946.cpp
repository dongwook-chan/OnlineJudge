#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;

        vector<pair<int, int>> rank_of_idx (N, pair<int, int>());
        for (int i = 0; i < N; ++i) {
            cin >> rank_of_idx[i].first;
            cin >> rank_of_idx[i].second;
            --rank_of_idx[i].first;
            --rank_of_idx[i].second;
        }

        sort(rank_of_idx.begin(), rank_of_idx.end(), [](pair<int, int> const &rank1, pair<int, int> const &rank2) -> bool const {
            return rank1.first < rank2.first;
        });

        //cout << "sorted" << endl;

        list<pair<int, int>> rank (rank_of_idx.begin(), rank_of_idx.end());

        //cout << "listed" << endl;

        for (list<pair<int, int>>::iterator it1 = rank.begin(); it1 != rank.end(); ++it1) {
            list<pair<int, int>>::iterator it2 = it1;
            for (++it2; it2 != rank.end();) {
                //cout << it1->first << "-" << it1->second << ", " << it2->first << "-" << it2->second << endl;  
                if (it2->second > it1->second) {
                    it2 = rank.erase(it2);
                }
                else {
                    ++it2;
                }
            }
        }

        cout << rank.size() << '\n';
    }

    return 0;
}