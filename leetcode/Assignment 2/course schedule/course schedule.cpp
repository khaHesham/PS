#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    
   bool DFS(vector<vector<int>> &adj, vector<bool> &visited, int node)
    {
        if(visited[node]) return false;
        visited[node] = true;

        for(auto neighbour: adj[node])
        {
            if(!DFS(adj,visited,neighbour)) return false;
        }

        visited[node] = false;

        //Since we know we can take this course so there is no need 
        //to repeat visiting prerequisites again
        adj[node].clear();  
            
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // numCourses is the number of courses required to finish

        // two challenges 
        /*
            [^] eleminate cycles. --> cycles means no solution
            [^] DFS then Top sort
        */

        // we need first to construct our adjacensy graph for DFS
        vector<vector<int>> adj(numCourses,vector<int>());
        for(auto edge: prerequisites)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        // we need to keep track of visited nodes
        vector<bool> visied(numCourses,false);

        // DFS on each node
        for (int i = 0; i < numCourses; i++)
        {
            if(!visied[i] && !DFS(adj,visied,i))
                return false;
        }
        return true;
    }
};
