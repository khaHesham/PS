class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1 ;
        int  postfix = 1;
        std::vector<int> out(nums.size(),1);

        for(int i = 0 ; i < nums.size(); i++)
        {
            out[i] = prefix;
            prefix *= nums[i];
        }
    
        for(int i = nums.size()-1; i >=0; i--)
        {
            out[i] *= postfix;
            postfix *= nums[i];
        }

        return out;
    }
};