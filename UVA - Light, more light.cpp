#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
    int zeroes = 0;
    int x;
    vector<int> bulbs;

    cin >> x;
    while (x != 0)
    {
        bulbs.push_back(x);
        cin >> x;
    }

    for (int j = 0; j < bulbs.size(); j++)
    {
        zeroes=0;
        for (int i = 1; i <= bulbs[j]; i++)
        {
            if (bulbs[j] % i == 0)
                zeroes++;
        }
        if (zeroes % 2 == 0)
            cout << "no\n";
        else
            cout << "yes\n";
    }

    return 0;
}