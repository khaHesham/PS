#include<iostream>
#include<algorithm>
#include<string>

using namespace std;





int main()
{
    
    string w1,w2;
    cin>>w1>>w2;
    int i=0;

    std::for_each(w1.begin(), w1.end(), [](char & c) {
        c = ::toupper(c);
    });

    std::for_each(w2.begin(), w2.end(), [](char & c) {
        c = ::toupper(c);
    });

   while( i < w1.size())
    {
        if(int(w1[i])==int(w2[i]))
        {
            i++;
        }
        else if(int(w1[i])>int(w2[i]))
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<-1;
            return 0;
        }

    }
    
    cout<<0;
    return 0;
}