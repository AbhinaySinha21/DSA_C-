#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Define an edge struct to represent the edges of the graph
struct Edge
{
    int src, dest, weight;
};

// Define a graph class to represent the graph
class Graph
{
public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V)
    {
        this->V = V;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight)
    {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    // Function to find the shortest path from a given source vertex to all other vertices using Bellman-Ford algorithm
    void shortestPath(int src)
    {
        vector<int> dist(V, INT_MAX); // Initialize all distances as infinite except source vertex
        dist[src] = 0;

        // Relax all edges V - 1 times to find the shortest path from src to all other vertices
        for (int i = 0; i < V - 1; i++)
        {
            for (auto edge : edges)
            {
                int u = edge.src;
                int v = edge.dest;
                int w = edge.weight;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative-weight cycles
        for (auto edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                cout << "Graph contains negative-weight cycle" << endl;
                return;
            }
        }

        // Print the shortest path from src to all other vertices
        cout << "Shortest path from vertex " << src << " to all other vertices:" << endl;
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                cout << "INF"
                     << " ";
            }
            else
            {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }

private:
    int V;              // Number of vertices
    vector<Edge> edges; // Vector to store edges of the graph
};

int main()
{
    // Create a graph object with 5 vertices
    Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    // Find the shortest path from vertex 0 to all other vertices
    graph.shortestPath(0);

    return 0;
}
