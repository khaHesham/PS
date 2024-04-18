/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    

public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> levels;
        std::queue<TreeNode*> BFS;
        BFS.push(root);

        while(!BFS.empty())
        {
            vector<int> currentLevel;
            int len = BFS.size();

            for(int i = 0; i < len; i++)
            {
               TreeNode * node = BFS.front();
               BFS.pop();
               if (node != NULL)
               {
                   currentLevel.push_back(node->val);
                   BFS.push(node->left);
                   BFS.push(node->right);
               }
            }

            if(currentLevel.size() != 0) levels.push_back(currentLevel);
        }

        return  levels;
    }
};