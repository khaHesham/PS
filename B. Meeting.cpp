#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

float Euclidean_distance(float x1, float x2, float y1, float y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool check(int x, int y, vector<vector<int>> radiators)
{
    for (int k = 0; k < radiators.size(); k++)
    {
        if (Euclidean_distance(radiators[k][0], x, radiators[k][1], y) <= radiators[k][2])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    int start_x = min({xa, xb});
    int end_x = (start_x == xa) ? xb : xa;

    int start_y = min({ya, yb});
    int end_y = (start_y == ya) ? yb : ya;

    int n;
    cin >> n;
    vector<vector<int>> radiators(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> radiators[i][j];
        }
    }

    int plankets = 0;

    for (int i = start_x; i <= end_x; i++)
    {
        plankets += check(i, ya, radiators) + check(i, yb, radiators);
    }

    for (int i = start_y + 1; i < end_y; i++)
    {
        plankets += check(xa, i, radiators) + check(xb, i, radiators);
    }

    cout << plankets;

    return 0;
}