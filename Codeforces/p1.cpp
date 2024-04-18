#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int z = 0;
    while (z < n) // testcases
    {

        int m, H, M;
        cin >> m >> H >> M;
        vector<pair<int, int>> alarms(m);
        for (int i = 0; i < m; i++)  //h m
        {
            cin >> alarms[i].first >> alarms[i].second;
        }

        for (int i = 0; i < m; i++)
        {
            int h_diff=alarms[i].first-H;
            int m_diff=alarms[i].second-M;
            
        }
        
        z++;
    }

    return 0;
}