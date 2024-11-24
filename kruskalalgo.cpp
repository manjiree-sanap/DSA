//A business house has several offices in different countries; they want to lease phone lines to connect them with each other and the phone company charges different rent to connect different pairs of cities. Business house wants to connect all its offices with a minimum total cost. Represent using appropriate data structure . Using Kruskal’s Algorithm
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    if (xset != yset)
        parent[xset] = yset;
}

void kruskalMST(Edge edges[], int numEdges, int numVertices) {
    sort(edges, edges + numEdges, compareEdges);
    int parent[5];
    fill(parent, parent + numVertices, -1);
    Edge result[5];
    int totalCost = 0;
    int e = 0;

    for (int i = 0; i < numEdges && e < numVertices - 1; i++) {
        int x = findParent(parent, edges[i].src);
        int y = findParent(parent, edges[i].dest);
        if (x != y) {
            result[e++] = edges[i];
            totalCost += edges[i].weight;
            unionSets(parent, x, y);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < e; i++) {
        cout << "Edge: " << result[i].src << " - " << result[i].dest << " with cost: " << result[i].weight << endl;
    }
    cout << "Total cost of MST using Kruskal's algorithm: " << totalCost << endl;
}

int main() {
    Edge edges[7] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    
    int numEdges = 7;

    kruskalMST(edges, numEdges, 5);
    return 0;
}
