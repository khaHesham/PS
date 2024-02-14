class Solution {
public:
    // function to compare two pairs for inbuilt sort
    static bool compare(pair<int,int> &p1,
                pair<int, int> &p2)
    {
        // If frequencies are same, compare
        // values
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }


    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> result;
        
        // get most frequent elements
        map<int, int> mp;

        // count freq
        for(int i=0; i < nums.size();i++)
            mp[nums[i]]++;
      
        //sort map and return top k
        pair<int, int> p[mp.size()];
        int i =0;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            p[i++] = make_pair(it->first, it->second);

        sort(p, p + mp.size(), compare);

        // push to result
        int j = 0;
        while(k--)
            result.push_back(p[j++].first);

        return result;

    }
};