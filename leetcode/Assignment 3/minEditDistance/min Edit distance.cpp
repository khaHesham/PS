#include <bits/stdc++.h>
using namespace std;

class Solution {
public:



    int BottomUp(string word1, string word2){
            vector<vector<int>> memo(word1.length() + 1,vector<int>(word2.length() + 1,0));

            // initialize the base case
            for(int i = 0;i < word1.length()+ 1;i++){
                memo[i][0] = i;
            }
            for (int j = 0; j < word2.length() + 1; j++) {
                memo[0][j] = j;
            }

            // algorithm
            for(int i = 1; i< word1.length() + 1; i++)
            {
                for(int j = 1; j < word2.length() + 1; j++)
                {
                    if(word1[i-1]==word2[j-1]) memo[i][j] = memo[i-1][j-1];
                    else{
                        // find min in memo[i-1][j], memo[i][j-1], memo[i-1][j-1]
                        memo[i][j] = 1 + min(memo[i-1][j],min(memo[i][j-1],memo[i-1][j-1]));
                    }
                }
            }
            return memo[word1.length()][word2.length()];
        }

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
        return BottomUp(word1,word2);
    }
};


int main() {
    Solution s;
    cout << s.minDistance("horse","ros") << endl;
    return 0;
}