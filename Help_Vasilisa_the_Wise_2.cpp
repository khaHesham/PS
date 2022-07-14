
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int c1, c2, d1, d2, r1, r2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int x1, x2, x3, x4;
    x1 = x2 = x3 = x4 = 1;
    bool found = false;


    while (x1 < 10 && !found)
    {
        while (x2 < 10 && !found)
        {
            while (x3 < 10 && !found)
            {
                while (x4 < 10 && !found)
                {
                    if (x1 + x3 == c1 && x1 + x4 == d1 && x1 + x2 == r1)
                    {
                        if (x3 + x4 == r2 && x3 + x2 == d2 && x2 + x4 == c2)
                        {
                            if (x1 != x2 && x1 != x3 && x1 != x4 && x2 != x3 && x2 != x4 && x3 != x4)
                            {
                                found = true;
                                cout << x1 << " " << x2 << endl;
                                cout << x3 << " " << x4 << endl;
                                return 0;
                            }
                        }
                    }
                    x4++;
                }
                x3++;
                x4 = 1;
            }
            x2++;
            x3 = x4 = 1;
        }

        x1++;
        x2 = x3 = x4 = 1;
    }

    cout << -1;
    return 0;
}