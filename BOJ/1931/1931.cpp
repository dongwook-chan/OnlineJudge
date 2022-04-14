#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_CLASS_CNT 100000

int N;
struct class_ {
    int b, e;
};
class_ classes[MAX_CLASS_CNT];
int ctr;

int main() {
    cin >> N;
    for(int n = 0; n < N; ++n) {
        int b, e;
        cin >> b >> e;
        classes[n] = {b, e};
    }

    sort(classes, classes + N, [](class_ const &class1, class_ const &class2) -> bool const{
        if(class1.e == class2.e) {
            return class1.b < class2.b;
        }
        return class1.e < class2.e;
    });

    for(int n = 0; n < N;) {
        int nb = classes[n].e;
        ++ctr;
        for(++n; n < N && classes[n].b < nb; ++n);
    }
    
    cout << ctr;

    return 0;
}