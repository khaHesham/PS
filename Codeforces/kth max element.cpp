#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int pos = nums.size() - k;
        return nums[pos];
    }
};

