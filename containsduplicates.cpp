class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> no_duplicates;
        for(int i=0; i< nums.size();i++)
        {
            no_duplicates.insert(nums[i]);
        }
        if(no_duplicates.size() != nums.size()) return true;
        else return false;
    }
};