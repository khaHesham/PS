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
    int n;
    cin >> n;
    vector<int> garden(n);
    for (int i = 0; i < n; i++)
    {
        cin >> garden[i];
    }

    // logic
    vector<int> temp;
    int curr, j, count;

    for (int i = 0; i < n; i++)
    {
        curr = garden[i];
        j = i - 1;
        count = 1;

        while (j >= 0 && garden[j] <= curr)
        {
            curr = garden[j];
            j -= 1;
            count++;
        }

        curr = garden[i];
        j = i + 1;
        while (j < n && garden[j] <= curr)
        {
            curr = garden[j];
            j += 1;
            count++;
        }

        temp.push_back(count);
    }

    cout << *max_element(temp.begin(), temp.end());

    return 0;
}