#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef long long ll;

using namespace std;

int main()
{

    string team1 = "";
    string team2 = "";

    int n;
    cin >> n;

    int team_1 = 0;
    int team_2 = 0;

    vector<string> teams(n);

    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> teams[i];
    }

    team1 = teams[0];
    for (int i = 0; i < n; i++)
    {
        if (teams[i] == team1)
            team_1++;
        else
        {
            team2 = teams[i];
            team_2++;
        }
    }

    if (team_1 > team_2)
        cout << team1;
    else
        cout << team2;

    return 0;
}