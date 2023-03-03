class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // find local min then find local max on its right
        int L = 0;
        int R = 1;
        int max_profit = 0;

        while(R < prices.size())
        {
            
            if(prices[L] < prices[R]) // profitable or not
            {
                int profit = prices[R]-prices[L];
                if(profit>max_profit) max_profit=profit;
            }
            else
                L = R;
            R++;
        }
        
        return max_profit;
    }
};