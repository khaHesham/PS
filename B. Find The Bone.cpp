#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> holes(m);
    for (int i = 0; i < m; i++)
    {
        cin >> holes[i];
    }

    vector<bool> cups(n + 1, false);

    int pos = 1; // initially at first position

    for (int i = 0; i < m; i++)
    {
        cups[holes[i]] = true;
    }

    int U, V;
    for (int i = 0; i < k; i++)
    {
        cin >> U >> V;
        if (cups[pos])
        {
            cout << pos;
            return 0;
        }
        if (pos == V)
            pos = U;
        else if (pos == U)
            pos = V;
    }

    cout << pos;

    return 0;
}