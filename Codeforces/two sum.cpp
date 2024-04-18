class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> map;
        vector<int> sol;
        for(int i=0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if(map.find(diff) != map.end())
            {
                sol.push_back(map[diff]);
                sol.push_back(i);
                return sol;
            }
            map[nums[i]]=i;
        }
        return sol;
    }
};