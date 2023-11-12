#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        // trivial conditions
        if (graph.empty())
            return {{}};

        if (graph.size() == 1)
            return {{0}};

        // all DFS paths to reach node n-1 from 0
        std::vector<std::vector<int>> allPaths;

        int goal = graph.size() - 1;

        std::stack<std::pair<int, vector<int>>> frontier; // stack to hold nodes
        frontier.push({0,{0}});                           // push first node to our stack with its neighbours

        while (!frontier.empty())
        {
            auto [current, path] = frontier.top();
            cout <<"current : "<<current <<" path: ";
            for (const auto &node : path)
            {
                std::cout << node << " ";
            }
            std::cout << std::endl;
            frontier.pop();

            if (current == goal) // goal found append path
            {
                allPaths.push_back(path);
                continue;
            }
            for (const auto &adj : graph[current]) // push all neighbours to stack
            {
                std::vector<int> newPath = path;
                newPath.push_back(adj);
                frontier.push({adj, newPath});
            }
        }
        return allPaths;
    }
};

int main()
{

    std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};

    Solution s;
    std::vector<std::vector<int>> allPaths = s.allPathsSourceTarget(graph);

    for (const auto &path : allPaths)
    {
        for (const auto &node : path)
        {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}