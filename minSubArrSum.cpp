class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {

    nums.insert(nums.begin(),0);
    for(int i=1; i < nums.size(); i++)  //construct integral array 
    {
        nums[i] += nums[i-1];
    }

    int k = 0;
    bool flag=false;
    while(k < nums.size())
    {
        for (int i = 0; i < (nums.size() - k); i++) {
                if (nums[i+k]-nums[i] >= target) {
                   return k;
                }
        }
        k++;
    }
    return 0;
    }
};