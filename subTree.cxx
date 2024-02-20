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
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if (!p || !q || (p->val != q->val)) return false;
        // iterate over both trees
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);    
    }

    bool isSubtree(TreeNode* p, TreeNode* q) {

        // base
        if(!p) return false;

        if(isSameTree(p,q)) return true;

        return isSubtree(p->left,q) || isSubtree(p->right,q);

    }
};