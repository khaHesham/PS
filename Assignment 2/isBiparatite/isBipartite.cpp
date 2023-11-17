#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        // from my point of view this seems to be graph coloring problem
        // we should have 3 colors : unvisited, visited set 1 , visited set 2
        // each node should have different color than their neighbours
        // how can i check if condition is satisified or not at the end?
        // dont need at the end if any edge is violated while coloring return false
        // else return true

        // Trivial conditions
        if (graph.size() == 0) return true;
        if (graph.size() == 1) return true;


        std::vector<int> color(graph.size(),0);    // 0 uncolored , 1 set A, 2 set B
        std::queue<pair<int,vector<int>>> frontier;

        for (int i = 0; i < graph.size(); i++ )
        {
            // check if node already colored skip it
            if(color[i]) continue;

            color[i] = 1;    // make it set A

            frontier.push({i,graph[i]});
            while(!frontier.empty())
            {
                
                int curr =frontier.front().first;
                vector<int> neighbours = frontier.front().second; 
                frontier.pop();

                for(auto neighbour: neighbours)
                {
                    if (!color[neighbour]) // if not colored then color with opp color
                    {
                        color[neighbour] = (color[curr]==1)? 2 : 1; 
                        frontier.push({neighbour,graph[neighbour]});
                    } else if(color[neighbour] == color[curr]) return false;

                }
            }
        }

        return true;



    }
};


int main(){
    Solution sol;
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout << sol.isBipartite(graph) << endl;
    return 0;
}