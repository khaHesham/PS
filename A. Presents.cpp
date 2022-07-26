#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> friends(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> friends[i];
    }

    vector<int> gifts;

    for (int i = 1; i < n + 1; i++)
    {
        int j = 1;
        while (j <= n)
        {
            if (i == friends[j])
            {
                gifts.push_back(j);
                break;
            }
            j++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << gifts[i] << " ";
    }

    return 0;
}