#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void find(int &I_src, int &J_src, vector<vector<int>> matrix)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 1)
            {
                I_src = i;
                J_src = j;
                return;
            }
        }
    }
    return;
}

int main()
{
    vector<vector<int>> matrix(5, vector<int>(5));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int I_src;
    int J_src;
    find(I_src, J_src, matrix);

    cout << abs(I_src - 2) + abs(J_src - 2);

    return 0;
}