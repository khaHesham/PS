#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string word;
    cin>>word;

    int upper = 0;
    int lower = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (int(word[i]) > 64 && int(word[i]) < 91)
            upper++;
        else
            lower++;
    }

    if (upper > lower)
    {
        std::for_each(word.begin(), word.end(), [](char &c)
                      { c = ::toupper(c); });
    }
    else
    {
        std::for_each(word.begin(), word.end(), [](char & c) {
        c = ::tolower(c);
    });
    }
    cout<<word;
    return 0;
}