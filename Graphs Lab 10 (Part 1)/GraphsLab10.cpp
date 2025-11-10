// GraphsLab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;


class Graph
{
private:
    vector<vector<int>> adj_matrix;

public:
    Graph(int vertices)
    {
        adj_matrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    /*
    * Adds an edge to the graph
    */
    void addEdge(int u, int v)
    {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    /*
    * Removes an edge from the graph
    */
    void removeEdge(int u, int v)
    {
        adj_matrix[u][v] = 0;
        adj_matrix[v][u] = 0;
    }

    /*
    * Checks if two vertices are adjacent to each other
    */
    bool isAdjacent(int vertex1, int vertex2)
    {
        int adj1 = adj_matrix[vertex1][vertex2];
        int adj2 = adj_matrix[vertex2][vertex1];

        return (adj1 == adj2) && (adj1 == 1);
    }

    /*
    * Conducts a Breadth-First Search starting at the given starting vertex.
    * Explores the graph level by level w/ a queue and finds the shortest path to a target
    */
    vector<int> bfs(int startVertex)
    {
        int size = adj_matrix.size();
        vector<bool> visited(size, false);
        vector<int> result;

        queue<int> q;

        // Start from given vertex
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            result.push_back(current);

            // Check all adjacent vertices
            for (int n = 0; n < size; n++)
            {
                // Check for an edge and neighbor that hasn't been visited
                if (adj_matrix[current][n] == 1 && !visited[n])
                {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }

        return result;
    }

    /*
    * Conducts a Depth-First Search starting at the given starting vertex
    * Explores the graph as far as possible down the branch before backtracking, which is done using a stack
    */
    vector<int> dfs(int startVertex)
    {
        int size = adj_matrix.size();
        vector<bool> visited(size, false);
        vector<int> result;

        stack<int> s;

        s.push(startVertex);

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            // Check if this vertex has already been visited
            if (!visited[current])
            {
                visited[current] = true;
                result.push_back(current);

                // Push neighbors in reverse order to maintain left-to-right traversal
                for (int n = size - 1; n >= 0; n--)
                {
                    if (adj_matrix[current][n] == 1 && !visited[n])
                    {
                        s.push(n);
                    }
                }
            }
        }

        return result;
    }

    void print()
    {
        cout << "Adjecency Matrix for the Graph: " << endl;
        int n = adj_matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void printVec(vector<int> vec)
{
    for (int vertex : vec)
    {
        cout << vertex << " ";
    }
    cout << endl;
}


int main()
{
    int vertices = 5;

    Graph graph = Graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    bool isAdj1 = graph.isAdjacent(0, 3);
    cout << "Are vertices 0 and 3 adjacent?: " << isAdj1 << endl;

    bool isAdj2 = graph.isAdjacent(1, 2);
    cout << "Are vertices 1 and 2 adjacent?: " << isAdj2 << endl;

    graph.print();

    vector<int> bfs = graph.bfs(0);
    cout << "BFS Results: " << endl;
    printVec(bfs);
    
    vector<int> dfs = graph.dfs(0);
    cout << "DFS Results: " << endl;
    printVec(dfs);


}
