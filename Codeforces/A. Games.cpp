#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> Games(n);

    for (int i = 0; i < n; i++)
    {
        int h,a;
        cin >> h >> a;
        Games[i].first = h;
        Games[i].second = a;
    }

    int number_of_games = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Games[i].first == Games[j].second)
                number_of_games++;
        }
    }

    cout << number_of_games;

    return 0;
}