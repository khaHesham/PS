class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }

    // vector<vector<string>> groupAnagrams(vector<string>& strs) {   // time limit

    //     vector<vector<string>> solution;
    //     vector<bool> used(strs.size(),false);

    //     for(int i=0;i<strs.size();i++){
    //         vector<string> sol;
    //         for(int j=0;j<strs.size();j++)
    //         {
    //             if(isAnagram(strs[j],strs[i]) && !used[j])
    //             {
    //                 sol.push_back(strs[j]);
    //                 used[j]=1;

    //             }
    //         }
    //         if(sol.size()>0)
    //         solution.push_back(sol);
    //     }
    //     return solution;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};