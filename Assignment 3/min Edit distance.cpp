#include <bits/stdc++.h>
using namespace std;

class Solution {
public:



    int solve(string word1,string word2, int i,int j, vector<vector<int>>& memo) {

        if (i == word1.length() && j == word2.length()) return 0;
        if (i == word1.length()) return word2.length() - j;
        if (j == word2.length()) return word1.length() - i;
        if (memo[i][j] != -1) return memo[i][j];

        if(word1[i] == word2[j]) return solve(word1,word2,i+1,j+1,memo);

        int insert = 1 + solve(word1,word2,i,j+1,memo);
        int remove = 1 + solve(word1,word2,i+1,j,memo);
        int replace = 1 + solve(word1,word2,i+1,j+1,memo);

        return memo[i][j] = min(insert,min(remove,replace));
        
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length() + 1,vector<int>(word2.length() + 1,-1));
        return solve(word1,word2,0,0,memo);
    }
};


int main() {
    Solution s;
    cout << s.minDistance("horse","ros") << endl;
    return 0;
}