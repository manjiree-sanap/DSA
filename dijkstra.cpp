//Use the map of the area around the college as the graph. Identify the prominent landmarks as nodes and find minimum distance to various landmarks from the college as the source. Represent this graph using an adjacency matrix. a) Find the shortest path using Dijkstra’s algorithm.
#include <iostream>
#include <limits.h>
using namespace std;

#define V 5

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    const char* landmarks[V] = {"A Building", "Cafeteria", "Ground   ", "FnF      ", "Mechanical Workshop"};
    
    cout << "Landmark \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << landmarks[i] << " \t " << dist[i] << endl;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 0, 0},
        {10, 0, 0, 12, 0},
        {15, 0, 0, 0, 5},
        {0, 12, 0, 0, 20},
        {0, 0, 5, 20, 0}
    };

    dijkstra(graph, 0);
    return 0;
}

