#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

   vector<int> twoSum(vector<int>& nums, int target,vector<bool> is_taken) {
        std::map<int, int> map;
        vector<int> sol;
        for(int i=0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if(map.find(diff) != map.end() && !is_taken[i] )
            {
                sol.push_back(map[diff]);
                sol.push_back(i);
                return sol;
            }
            map[nums[i]] = i;
        }
        return sol;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<bool> is_taken(nums.size(),false);

        for(int i=0; i<nums.size();i++)
        {
            vector<int> sub_sol = twoSum(nums,-nums[i],is_taken);
            if(sub_sol.size()!=0 && i !=sub_sol[0] && i != sub_sol[1])
            {
                sub_sol.push_back(i);
                solution.push_back(sub_sol);
                is_taken[i]=true;
                is_taken[sub_sol[0]]=true;
                is_taken[sub_sol[1]]=true;
            }

        }
        return solution;
    }

int main()
{
    vector<int> num;

    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(-1);
    num.push_back(-4);

    vector<vector<int>> sol = threeSum(num);

    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[i].size(); j++)
        {
            cout<<sol[i][j]<<" ";

        }
        cout<<endl;
        
    }

    

    return 0;
}