#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string name;
    string temp;
    cin >> name;

    int destinct = 0;

    for (int i = 0; i < name.size(); i++)
    {
        if (temp.find(name[i]) == string::npos)
        {
            destinct++;
            temp.push_back(name[i]);
        }
    }

    if (destinct % 2 == 0)
        cout << "CHAT WITH HER!";
    else
        cout << "IGNORE HIM!";

    return 0;
}