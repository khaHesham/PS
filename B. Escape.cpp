#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    // vp spped of person
    // vd speed of dragon
    // t hours before dragon discover escape
    // f time spend in the cave

    float dp = t * vp;
    int perl = 0;
    float td, t_return;

    if (vp < vd)
    {
        while (dp < c)
        {
            td = dp / (vd - vp);
            dp = dp + td * vp;
            if (dp >= c)
                break;

            t_return = (dp / vd) + f;
            dp += t_return * vp;
            perl++;
        }
    }

    cout << perl;

    return 0;
}