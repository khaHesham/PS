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
public:
    int solve(TreeNode* root,bool &balanced){
        if(!root) return 0;
        int left_T = solve(root->left,balanced);
        int right_T = solve(root->right,balanced);

        if(abs(left_T-right_T) > 1) balanced = false;

        return 1 + max(left_T,right_T);
    }
    bool isBalanced(TreeNode* root) {

        bool balanced = true;
        solve(root,balanced);

        return balanced;
        
    }
};