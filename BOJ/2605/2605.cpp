#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    int N;
    cin >> N;

    list<int> l;

    for (int i = 1; i <= N; ++i)
    {
        int n;
        cin >> n;

        list<int>::iterator b = prev(l.end(), n);

        l.insert(b, i);
    }

    for (int e : l)
    {
        cout << e << ' ';
    }

    return 0;
}