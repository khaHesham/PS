#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long _8x8_chess_Board(vector<vector<int>> &matrix, vector<vector<bool>> &used, int i, int j, int W_B)
{
    if (i < 7 || j < 7)
    {
        return 0;
    }

    if (used[i][j])
    {
        return 0;
    }

    used[i][j] = true;
    if (W_B)
        return 1 + _8x8_chess_Board(matrix, used, i - 1, j, 0) + _8x8_chess_Board(matrix, used, i - 1, j - 1, 1) + _8x8_chess_Board(matrix, used, i, j - 1, 0);
    else
        return _8x8_chess_Board(matrix, used, i - 1, j, 1) + _8x8_chess_Board(matrix, used, i - 1, j - 1, 0) + _8x8_chess_Board(matrix, used, i, j - 1, 1);
}

int main()
{
    int n, m, W_B;

    cin >> n >> m >> W_B;

    while ((n != 0) && (m != 0))
    {
        vector<vector<int>> matrix(n, vector<int>(m));
        vector<vector<bool>> used(n, vector<bool>(m, false));
        cout << _8x8_chess_Board(matrix, used, n - 1, m - 1, W_B) << endl;
        cin >> n >> m >> W_B;
    }

    return 0;
}