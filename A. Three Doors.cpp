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

    int t;
    cin >> t;
    vector<string> out;

    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        int a, b, c;
        cin >> a >> b >> c;
        if (x == 1)
        {
            x = a;
            if (x == 2)
            {
                x = b;
                if (x == 3)
                    out.push_back("YES");
                else
                    out.push_back("NO");
            }
            else if (x == 3)
            {
                x = c;
                if (x == 2)
                    out.push_back("YES");
                else
                    out.push_back("NO");
            }
            else
                out.push_back("NO");
        }

        else if (x == 2)
        {
            x = b;
            if (x == 1)
            {
                x = a;
                if (x == 3)
                    out.push_back("YES");
                else
                    out.push_back("NO");
            }
            else if (x == 3)
            {
                x = c;
                if (x == 1)
                    out.push_back("YES");
                else
                    out.push_back("NO");
            }
            else
                out.push_back("NO");
        }
        else if (x == 3)
        {
            x = c;
            if (x == 2)
            {
                x = b;
                if (x == 1)
                    out.push_back("YES");
                else
                    out.push_back("NO");
            }
            else if (x == 1)
            {
                x = a;
                if (x == 2)
                    out.push_back("YES");
                else
                    out.push_back("NO");
            }
            else
                out.push_back("NO");
        }
    }

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }

    return 0;
}