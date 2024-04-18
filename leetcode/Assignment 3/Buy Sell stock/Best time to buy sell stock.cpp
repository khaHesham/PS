#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[5000][2];
    int solve(vector<int>& prices,int i,bool buying){
        // base case
        if(i >= prices.size()) return 0;
        if(memo[i][buying] != -1) return memo[i][buying];

        // if buying
        if(buying){
            // we can buy or skip
            int buy = -prices[i] + solve(prices,i+1,!buying);
            int skip = solve(prices,i+1,buying);
            return memo[i][buying] = max(buy,skip);
        }
        else{
            // we can sell or skip
            int sell = prices[i] + solve(prices,i+2,!buying);
            int skip = solve(prices,i+1,buying);
            return memo[i][buying] = max(sell,skip);
        }

    }
    int maxProfit(vector<int>& prices) {
        memset(memo,-1,sizeof(memo));
        return solve(prices,0,true);
    }
};



int main() {
    Solution s;
    vector<int> nums = {1,2,3,0,2};
    cout << s.maxProfit(nums) << endl;
}