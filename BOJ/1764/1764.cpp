#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_set<string> people_unheard;
    while(N--) {
        string person_unheard;
        cin >> person_unheard;
        people_unheard.emplace(person_unheard);
    }

    vector<string> people_unseen;
    while(M--) {
        string person_unseen;
        cin >> person_unseen;
        if (people_unheard.find(person_unseen) != people_unheard.end()) {
            people_unseen.push_back(person_unseen);
        }
    }

    sort(people_unseen.begin(), people_unseen.end());

    cout << people_unseen.size() << '\n';
    for (auto person_unseen : people_unseen) {
        cout << person_unseen << '\n';
    }

    return 0;
}