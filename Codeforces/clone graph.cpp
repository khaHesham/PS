/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> map;

    Node* DFS(Node* node)
    {
        if(node == NULL) return NULL;

        if(map.find(node) != map.end()) // exists 
            return map[node];
        map[node] = new Node(node->val,{});
        for(auto adj: node -> neighbors) // travel in adjcant
            {
                map[node] -> neighbors.push_back(DFS(adj)); //add copy
            }

        return map[node];

    }

    Node* cloneGraph(Node* node) {
        return DFS(node);
    }
};