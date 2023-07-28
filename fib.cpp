class Solution {
public:
 int recursive(int n,vector<int> &memo)
    {
        if(n == 0 ) 
            return 0;
        if(n == 1) 
            return 1;

        if(memo[n] == -1) 
            memo[n] = recursive(n-1,memo) + recursive(n-2,memo);

        return memo[n];
    }
    int fib(int n) {

        vector<int> memo(n + 1,-1);
        return recursive(n,memo); 
    }
};