//) A business house has several offices in different countries; they want to lease phone lines to connect them with each other and the phone company charges different rent to connect different pairs of cities. Business house wants to connect all its offices with a minimum total cost. Represent using appropriate data structure. Apply a) Prim’s 
#include <iostream>
using namespace std;

void primMST(int graph[5][5], int numVertices) {
    bool selected[5] = {false};
    selected[0] = true;
    int edges = 0;
    int totalCost = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";

    while (edges < numVertices - 1) {
        int minCost = INT16_MAX;
        int a = 0, b = 0;

        for (int i = 0; i < numVertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < numVertices; j++) {
                    if (!selected[j] && graph[i][j] != 0) {
                        if (minCost > graph[i][j]) {
                            minCost = graph[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }

        selected[b] = true;
        edges++;
        totalCost += minCost;
        cout << "Edge: " << a << " - " << b << " with cost: " << minCost << endl;
    }

    cout << "Total cost of MST using Prim's algorithm: " << totalCost << endl;
}

int main() {
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, 5);
    return 0;
}
