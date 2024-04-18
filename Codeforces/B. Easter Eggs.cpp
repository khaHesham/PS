#include <iostream>
#include <algorithm>
#include <vector>

#define all(v) ((v).begin()),((v).end())
#define sz(v)  ((int)((v).size()))
typedef vector<int> vi;
typedef long long ll;

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