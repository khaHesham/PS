#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<string>> matrix(n, vector<string>(n, "S"));

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < n; j += 2)
            {
                if (k > 0)
                {
                    matrix[i][j] = "L";
                    k--;
                }
            }
        else
            for (int j = 1; j < n; j += 2)
            {
                if (k > 0)
                {
                    matrix[i][j] = "L";
                    k--;
                }
            }
    }

    if (k > 0)
    {
        cout << "NO";
        return 0;
    }
    else
        cout << "YES\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}