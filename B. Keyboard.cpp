#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include<cmath>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef long long ll;

using namespace std;

void find_key(int &I_src, int &J_src, int n, int m, char src, vector<vector<char>> matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == src)
            {
                I_src = i;
                J_src = j;
                return;
            }
        }
    }
    return;
}

bool find_shift(int &I_src, int &J_src,int n ,int m,vector<vector<int>> &matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                I_src = i;
                J_src = j;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<char>> keyboard(n, vector<char>(m));
    vector<vector<int>> shifts(n, vector<int>(m, 0));
    bool shift = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> keyboard[i][j];

            if (keyboard[i][j] == 'S')
            {
                shifts[i][j] = 1;
                shift = true;
            }
        }
    }

    int q;
    string Text;
    cin >> Text;

    int hand = 0;

    for (int i = 0; i < Text.size(); i++)
    {
        int I = -1;
        int J = -1;
        find_key(I, J, Text[i], n, m, keyboard);
        if (I == -1 || j == -1)
        {
            cout << -1;
            return 0;
        }

        if (int(Text[i]) > 64 && int(Text[i]) < 91 && shift) // at least one shift exist
        {
            int I2=-1;
            int j2=-1;
            while (find_shift(I2,J2,n,m,shifts))
            {
                if(sqrt(pow(I-I2,2)+pow(J-J2,2))>x)
                {
                    
                }
                else break;
            }
            
        }
    }

    return 0;
}