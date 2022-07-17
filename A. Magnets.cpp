#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> magnets(n);

    for (int i = 0; i < n; i++)
    {
        cin >> magnets[i];
    }

    string pre = magnets[0];
    int groups = 1;

    for (int i = 1; i < n; i++)
    {
        if (pre != magnets[i])
        {
            groups++;
            pre=magnets[i];
        }
    }

    cout<<groups<<endl;

    return 0;
}