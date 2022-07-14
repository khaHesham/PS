#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{

    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    if ((a1 * b1 >= a2 * b2 + a3 * b3))
    {
        if (max(a1, b1) - max(a3, b3) > max(a1, b1) - max(a2, b2))
        {
            a1 = abs(a1 - a2);
            b1 = abs(b1 - b2);
            if (a1 * b1 >= a3 * b3)
            {
                if (max(a1, b1) >= max(a3, b3))
                {
                    if (min(a1, b1) >= min(a3, b3))
                    {
                        cout << "YES";
                        return 0;
                    }
                }
            }
        }
        else
        {
            a1 = abs(a1 - a3);
            b1 = abs(b1 - b3);
            if (a1 * b1 >= a2 * b2)
            {
                if (max(a1, b1) >= max(a2, b2))
                {
                    if (min(a1, b1) >= min(a2, b2))
                    {
                        cout << "YES";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO";
    return 0;
}