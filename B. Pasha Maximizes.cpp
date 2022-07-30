#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int k;
    long long a;
    cin >> a >> k;
    long long s;
    long long n = 1;

    vector<int> temp;

    while (s > 0)
    {
        s = a / n;
        n *= 10;
        if (s == 0)
            break;

        temp.push_back(s % 10);
    }
    reverse(temp.begin(), temp.end());

    for (int i = 0; i < temp.size() - 1; i++)
    {
        int j = i + 1;

        while (j >= 0)
        {
            if (k > 0)
            {
                if (temp[j] != 0)
                {
                    if (temp[j] > temp[j - 1])
                    {
                        int te = temp[j - 1];
                        temp[j - 1] = temp[j];
                        temp[j] = te;
                        k--;
                        j--;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else
                break;
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }

    return 0;
}