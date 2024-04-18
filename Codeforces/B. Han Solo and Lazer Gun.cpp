#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, x0, y0;
    cin >> n >> x0 >> y0;

    vector<int> x_pos(n);
    vector<int> y_pos(n);
    vector<bool> ded(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> x_pos[i] >> y_pos[i];
    }

    int shots = 0;

    for (int j = 0; j < n; j++)
    {

        if (ded[j] == true)
            continue;

        shots++;
        int delta_y = y_pos[j] - y0;
        int delta_x = x_pos[j] - x0;
        ded[j] = true;

        for (int i = 0; i < n; i++)
        {
            int d2_y = y_pos[i] - y0;
            int d2_x = x_pos[i] - x0;

            if (!ded[i] && d2_y * delta_x == d2_x * delta_y)
            {
                ded[i] = true;
            }
        }
    }

    cout << shots;
    return 0;
}