/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        std::queue<Node*> BFS;
        BFS.push(root);

        while(!BFS.empty())
        {
            vector<int> currentLevel;
            int len = BFS.size();

            for(int i = 0; i < len; i++)
            {
               Node * node = BFS.front();
               BFS.pop();
               if (node != NULL)
               {
                   currentLevel.push_back(node->val);
                   for(auto child : node->children)
                        BFS.push(child);
               }
            }

            if(currentLevel.size() != 0) levels.push_back(currentLevel);
        }

        return  levels;
    }
};