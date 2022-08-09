#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    int z = 0;
    vector<int> numbers;

    while (z < n)
    {

        int s;
        cin >> s;
        vector<int> arr(s);

        for (int i = 0; i < s; i++)
        {
            cin >> arr[i];
        }

        int max = *max_element(arr.begin(), arr.end());

        bool flag = false;
        int count = 0;
        int i = 0;
        while (i < s)
        {
            flag = false;
            while (arr[i] < max)
            {
                arr[i] += (arr[i] % 10);
            }

            if (arr[i] != max)
            {
                flag = true;
                count++;
                max += (max % 10);
                i = -1;
                if (count > 10)
                    break;
            }
            i++;
        }

        if (!false)
            cout << "YES";
        else
            cout << "NO";

        z++;
    }
    return 0;
}