class Solution {
public:
int recursive(int n,vector<int>& cost,vector<int> &memo)
    {
        if(n < 0) return 0;
        if(n == 0 || n==2 ) 
            return cost[n];

        if(memo[n] == -1) 
            memo[n] = cost[n] + min(recursive(n-1,cost,memo), recursive(n-2,cost,memo));

        return memo[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> memo(cost.size(),-1);
        return min(recursive(cost.size()-1,cost,memo),recursive(cost.size()-2,cost,memo));
    }
};