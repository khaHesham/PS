#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string ans = "ROYGBIV";
    for (int i = ans.size(); ans.size() < n; i++)
    {
        ans += ans[i - 4];
    }
    cout << ans;

    return 0;
}