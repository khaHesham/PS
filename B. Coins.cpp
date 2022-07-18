#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{

    vector<string> input;
    string x;
    vector<char> output;

    map<char, int> in;

    while (cin >> x)
    {
        input.push_back(x);
    }

    in.insert({'A', 0});
    in.insert({'B', 0});
    in.insert({'C', 0});

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i][1] == '>')
            in[input[i][0]]++;
        else
            in[input[i][2]]++;
    }

    if (in['A'] == 1 && in['B'] == 1 && in['C'] == 1)
    {
        cout << "Impossible";
        return 0;
    }

    if (in['A'] == 0)
        cout << "A";
    else if (in['B'] == 0)
        cout << "B";
    else if (in['C'] == 0)
        cout << "C";

    if (in['A'] == 1)
        cout << "A";
    else if (in['B'] == 1)
        cout << "B";
    else if (in['C'] == 1)
        cout << "C";

    if (in['A'] == 2)
        cout << "A";
    else if (in['B'] == 2)
        cout << "B";
    else if (in['C'] == 2)
        cout << "C";

    return 0;
}