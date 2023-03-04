#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

class Graphs
{ // handler for graph algorithms (BFS, DFS, TOPOlogical, ...)
public:
    int V; // number of verticies

    // Constructor
    Graphs(int v)
    {
        V = v;
    }

    // * BFS Traversal of an undirected and unweighted graph.  (finds shoertest path also)
    void createAndAddEdge_BFS(vector<int> adjList[], int u, int v)
    {
        adjList[u].push_back(v);
        // adjList[v].push_back(u); // do this because undirected graph
    }

    void BFS(vector<int> adjList[], int source)
    {
        vector<bool> visitedVertex(V, false);
        queue<int> Q; // set up Queue for BFS
        int v;
        Q.push(source);
        while (!Q.empty())
        {
            v = Q.front();
            visitedVertex.at(v) = true;
            Q.pop();
            cout << v << " ";                                                                 // Print Vertex
            for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // Visit all children
                if (!visitedVertex.at(*it))
                {
                    Q.push(*it); // Push unvisted vertex onto the queue
                    visitedVertex.at(*it) = true;
                } // if not visited
        }         // While Queue is not empty
        cout << endl;
    } // BFS

    //* DFS Traversal of an undirected and unweighted graph.
    void DFS_iterative(vector<int> adjList[], int source)
    {

        vector<bool> visitedVertex(V, false);
        stack<int> S; // set up Queue for BFS
        int v;
        S.push(source);
        while (!S.empty())
        {
            v = S.top();
            visitedVertex.at(v) = true;
            S.pop();
            cout << v << " ";                                                                 // Print Vertex
            for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // Go as far as we can go and then backtrack
                if (!visitedVertex.at(*it))
                {
                    S.push(*it); // Push unvisted vertex onto the stack
                    visitedVertex.at(*it) = true;
                } // if not visited
        }         // While Stack is not empty
        cout << endl;
    } // DFS

    void DFS_Recursive(vector<int> adjList[], vector<bool> visitedVertex, int source)
    {
        visitedVertex.at(source) = true;
        cout << source << " "; // Print Vertex
        for (vector<int>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
            if (!visitedVertex[*it])
                this->DFS_Recursive(adjList, visitedVertex, *it); // Go as far as possible by recursing.
    }

    vector<int> TopologicalSort(vector<int> adjList[])
    {
        vector<int> inDegree(V, 0);           // Initialize all in-Degrees to 0
        vector<bool> visitedVertex(V, false); // Mark everything as unvisited
        vector<int> T;                        // This will store the vertices that TopologicalSort visits in order.
        queue<int> Q;                         // set up Queue for BFS
        int source;
        int v;

        for (int i = 0; i < V; i++)                                                           // for all vertices in the graph
            for (vector<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++) // visit it's neighbors
                inDegree.at(*it)++;                                                           // increment inDegree of that child

        for (int i = 0; i < V; i++)
            if (inDegree.at(i) == 0)
            {
                source = i;
                Q.push(source);                  // Push it onto the queue as a starting point for BFS
                visitedVertex.at(source) = true; // Mark it true
                break;
            } // Found a vertex with 0 inDegree -> This will be our source for Topological Sort

        while (!Q.empty())
        {
            v = Q.front(); // Get v
            Q.pop();
            T.push_back(v); // Add to T-Vector

            /* Now to proceed with Topological Sort, we remove the vertex and all its corresponding edges.
             * Which means, the in-degree's of all it's neighbors will be reduced by 1
             */

            for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // Visit all neighbors
                if (!visitedVertex.at(*it))
                {
                    inDegree.at(*it)--; // Decrement inDegree of the neighbor, because its parent vertex has been removed
                    if (inDegree.at(*it) == 0)
                    {
                        Q.push(*it);                  // Push the vertex with least inDegree -> New Source
                        visitedVertex.at(*it) = true; // Mark it to be true
                    }                                 // Find new source
                }                                     // if not visited
        }
        return T; // While Queue is not empty
    }
};

int main()
{
    const int numVertices = 6; // 6 vertices (0,1,2,3,4,5)
    int source = 0;
    vector<int> adjList[numVertices]; // Create an array of vectors

    Graphs *gf = new Graphs(numVertices);

    //* Testing BFS algorithm
    gf->createAndAddEdge_BFS(adjList, 0, 1);
    gf->createAndAddEdge_BFS(adjList, 0, 2);
    gf->createAndAddEdge_BFS(adjList, 1, 5);
    gf->createAndAddEdge_BFS(adjList, 2, 3);
    gf->createAndAddEdge_BFS(adjList, 2, 4);
    gf->createAndAddEdge_BFS(adjList, 3, 3);
    gf->createAndAddEdge_BFS(adjList, 4, 4);
    gf->createAndAddEdge_BFS(adjList, 5, 5);

    gf->BFS(adjList, 0); // source = 0
    // should print 0 1 2 5 3 4

    //* Testing DFS
    gf->DFS_iterative(adjList, 0);
    // should print 0 2 4 3 1 5

    vector<bool> visitedVertex(numVertices, false);
    gf->DFS_Recursive(adjList, visitedVertex, 0);
    // may not print same as iterative DFS but answer should also true
    // in our case it prints : 0 1 5 2 3 4

    //* Testing Topological sort of DAG

    vector<int> DAG[numVertices]; // Create an array of vectors
    gf->createAndAddEdge_BFS(DAG, 0, 1);
    gf->createAndAddEdge_BFS(DAG, 0, 3);
    gf->createAndAddEdge_BFS(DAG, 1, 2);
    gf->createAndAddEdge_BFS(DAG, 1, 3);
    gf->createAndAddEdge_BFS(DAG, 2, 3);
    gf->createAndAddEdge_BFS(DAG, 2, 4);
    gf->createAndAddEdge_BFS(DAG, 2, 5);
    gf->createAndAddEdge_BFS(DAG, 3, 4);
    gf->createAndAddEdge_BFS(DAG, 3, 5);
    gf->createAndAddEdge_BFS(DAG, 4, 5);

    vector<int> T = gf->TopologicalSort(DAG);
    cout << "\nTopological Sort for the given DAG: ";
    for (int i = 0; i < T.size(); i++)
        cout << T.at(i) << " ";
    cout << endl;
    // Should Print: 0 1 2 3 4 5


    



    return 0;
}