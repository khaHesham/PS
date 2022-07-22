#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> choclate(n);

    bool ones = false;

    for (int i = 0; i < n; i++)
    {
        cin >> choclate[i];
        if (choclate[i] == 1)
            ones = true;
    }

    if (!ones)
    {
        cout << 0;
        return 0;
    }

    long long ways = 1;
    for (int i = 0; i < n; i++)
    {
        if (choclate[i] == 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (choclate[j] == 1)
                {
                    ways = ways * (j - i);
                    break;
                }
            }
        }
    }

    cout << ways;
    return 0;
}
