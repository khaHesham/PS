class Solution {
public:
    

    int recursive(int n,vector<int> &memo)
    {
        if(n == 0 || n==1 ) 
            return 1;

        if(memo[n] == -1) 
            memo[n] = recursive(n-1,memo) + recursive(n-2,memo);

        return memo[n];
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1,-1);
        return recursive(n,memo);
    }
};