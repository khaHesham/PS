#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int i = 2;
    int mul = x;

    vector<int> muls;

    while (true)
    {
       
        if (mul == 1)
            break;

        if (mul % i == 0)
        {
            mul = mul / i;
            muls.push_back(i);
        }
        else
            i++;
    }

    sort(muls.begin(),muls.end(),greater<>());

    vector<bool>isused(muls.size(),false);
    vector<int>final;

    for (int i = 0; i < muls.size(); i++)
    {
        if(isused[i]==true) continue;

        if(muls[i]==2) final.push_back(muls[i]);

        int fact=muls[i];
        int j=0;
        while(j<muls.size())
        {
            while(muls[j]==fact-1)
            {
                
            }
                
        }
        

    }
    






    for (int i = 0; i < muls.size(); i++)
    {
        cout << muls[i]<<endl;
    }

    return 0;
}