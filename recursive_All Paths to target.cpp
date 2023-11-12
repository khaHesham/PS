class Solution {
public:
    void dfs(int current,int goal,vector<int>&path,vector<vector<int>>& graph,vector<vector<int>>& allPaths){
        path.push_back(current);

        if(current == goal)
            allPaths.push_back(path);

        for(const auto & adj: graph[current])
        {
           dfs(adj,goal,path,graph,allPaths); 
        }

        path.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> path;
        dfs(0,graph.size() - 1,path,graph,allPaths);
        return allPaths;
    }
};