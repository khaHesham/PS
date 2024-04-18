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
    void inOrder(TreeNode* root,vector<int>&result)
    {
        if(!root) return;

        inOrder(root->left,result);
        result.push_back(root->val);
        inOrder(root->right,result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();

        vector<int> result;
        inOrder(root,result);

        return result;

    }
};