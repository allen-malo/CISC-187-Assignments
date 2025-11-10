// GraphsLab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class WeightedGraph {
private:
    // Instead of just 0 or 1, store the actual weight
    vector<vector<int>> adj_matrix;
    int vertices;

public:
    WeightedGraph(int vertices) 
    {
        this->vertices = vertices;
        // Initialize with a large value (infinity) meaning "no edge"
        adj_matrix = vector<vector<int>>(vertices, vector<int>(vertices, INT_MAX));

        // Distance from a vertex to itself is 0
        for (int i = 0; i < vertices; i++) 
        {
            adj_matrix[i][i] = 0;
        }
    }

    // Add edge with a specific weight
    void addEdge(int u, int v, int weight) 
    {
        adj_matrix[u][v] = weight;
        adj_matrix[v][u] = weight; // For undirected graph
    }

    // For directed graph
    void addDirectedEdge(int u, int v, int weight) 
    {
        adj_matrix[u][v] = weight;
    }

    // Dijkstra's Algorithm
    vector<int> dijkstra(int start) 
    {
        vector<int> distance(vertices, INT_MAX);
        vector<bool> visited(vertices, false);

        distance[start] = 0;

        for (int count = 0; count < vertices - 1; count++) 
        {
            // Find minimum distance vertex not yet visited
            int minDist = INT_MAX;
            int minIndex = -1;

            for (int v = 0; v < vertices; v++) 
            {
                if (!visited[v] && distance[v] < minDist) 
                {
                    minDist = distance[v];
                    minIndex = v;
                }
            }

            if (minIndex == -1) break; // No more reachable vertices

            visited[minIndex] = true;

            // Update distances of adjacent vertices
            for (int v = 0; v < vertices; v++) 
            {
                if (!visited[v] && adj_matrix[minIndex][v] != INT_MAX && distance[minIndex] != INT_MAX && distance[minIndex] + adj_matrix[minIndex][v] < distance[v]) 
                {
                    distance[v] = distance[minIndex] + adj_matrix[minIndex][v];
                }
            }
        }

        return distance;
    }

    void printGraph() 
    {
        cout << "Adjacency Matrix (INT_MAX = no edge):\n";
        cout << "   ";
        for (int i = 0; i < vertices; i++) {
            cout << i << "    ";
        }
        cout << "\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < vertices; j++) {
                if (adj_matrix[i][j] == INT_MAX) {
                    cout << "INF  ";
                }
                else {
                    cout << adj_matrix[i][j] << "    ";
                }
            }
            cout << "\n";
        }
    }

    void printShortestPaths(int start) 
    {
        vector<int> distances = dijkstra(start);

        cout << "\nShortest paths from vertex " << start << ":\n";
        for (int i = 0; i < vertices; i++) {
            cout << "To vertex " << i << ": ";
            if (distances[i] == INT_MAX) {
                cout << "No path exists\n";
            }
            else {
                cout << distances[i] << "\n";
            }
        }
    }
};

void printVec(vector<int> vec)
{
    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    WeightedGraph wg = WeightedGraph(3);
    // Here, A = 0, B = 1, and C = 2
    wg.addDirectedEdge(0, 1, 3); // Weight from A to B is 3
    wg.addDirectedEdge(0, 2, 2); // Weight from A to C is 2
    wg.addDirectedEdge(1, 2, -12); // Weight from B to C is -12

    wg.printShortestPaths(0);
}

