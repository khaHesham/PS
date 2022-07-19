#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef long long ll;

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> fence(n + 1); // i -> 1 2 3 4 ... n
    fence[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        cin >> fence[i];
        fence[i]+=fence[i-1];
    }

    int min=INT_MAX;
    int z=0;


    for (int i = k; i <= n ; i++)
    {
      if(min>fence[i]-fence[i-k])
      {
        z=i;
        min=fence[i]-fence[i-k];
      }
    }

    
    cout << z-k+1;

    return 0;
}