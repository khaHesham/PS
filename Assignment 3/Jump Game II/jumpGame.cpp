#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        vector<int> memo(nums.size(),INT_MAX);
        memo[0] = 0; // base case

        // try every possible jump
        for(int i = 0;i<nums.size();i++){
            for(int j =1; j<=nums[i];j++){
                if(i + j < nums.size()) memo[i+j] = min(memo[i+j],memo[i] + 1);
            } 
        }

        return memo[nums.size()-1];
        
    }
};


int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.jump(nums) << endl;
}