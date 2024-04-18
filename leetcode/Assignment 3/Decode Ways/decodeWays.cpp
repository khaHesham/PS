#include <bits/stdc++.h>
using namespace std;


class Solution {
public:



    int solve(string s,int i, vector<int>& memo) {
        // Base case
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(i == s.length() - 1) return 1;

        // memoization
        if(memo[i] != -1) return memo[i];


        int ans = solve(s,i+1,memo);
        // check if we can take 2 digits
        if(stoi(s.substr(i,2)) <= 26) ans += solve(s,i+2,memo);

        return memo[i] = ans;
    }

    int numDecodings(string s) {
        vector<int> memo(s.length() + 1,-1);
      
       return solve(s,0,memo);
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("12") << endl;
}