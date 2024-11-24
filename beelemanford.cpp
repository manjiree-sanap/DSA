//Use the map of the area around the college as the graph. Identify the prominent landmarks as nodes and find minimum distance to various landmarks from the college as the source. Represent this graph using an adjacency matrix. Find the shortest path using Bellman-Ford algorithm.
#include <iostream>
#include <limits.h>
using namespace std;

#define V 5
#define E 8

struct Edge {
    int src, dest, weight;
};

void bellmanFord(Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    const char* landmarks[V] = {"A Building", "Cafeteria", "Ground   ", "FnF\t", "Mechanical Workshop"};
    
    cout << "Landmark \tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << landmarks[i] << " \t" << dist[i] << endl;

    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            cout << "Graph contains negative weight cycle\n";
    }
}

int main() {
    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 15},
        {1, 3, 12},
        {2, 4, 5},
        {1, 4, 0},
        {3, 4, 20},
        {2, 3, 0},
        {4, 3, 20}
    };

    bellmanFord(edges, 0);
    return 0;
}
