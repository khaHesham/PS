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

    int n, m;
    cin >> n >> m;

    vector<int> columns(n);
    vector<int> damage;
    for (int i = 0; i < n; i++)
    {
        cin >> columns[i];
    }

    int s, t;

    for (int j = 0; j < m; j++)
    {

        cin >> s >> t;

        s -= 1;
        t -= 1;
        int damage_ = 0;

        if (s < t)
        {
            for (int i = s; i < t; i++)
            {
                if (i + 1 < n)
                    if (columns[i] > columns[i + 1])
                    {
                        damage_ = damage_ + (columns[i] - columns[i + 1]);
                    }
            }
        }
        else
        {
            for (int i = s; i > t; i--)
            {
                if (i - 1 >= 0)
                    if (columns[i] > columns[i - 1])
                    {
                        damage_ = damage_ + (columns[i] - columns[i - 1]);
                    }
            }
        }
        
        damage.push_back(damage_);
    }

    for (int i = 0; i < damage.size(); i++)
    {
        cout << damage[i] << endl;
    }

    return 0;
}