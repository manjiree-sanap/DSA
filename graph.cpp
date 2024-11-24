// Create a graph using adjacency list representation. Perform graph traversal using BFS and DFS.
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int vertex;
    Node *next;
    Node(int v) : vertex(v), next(NULL) {}
};

class Graph {
    public:
        int no_of_vertices;
        Node* Alist[6];

        Graph(int numberOfVertices) {
            no_of_vertices = numberOfVertices;
            for (int i = 0; i < no_of_vertices; ++i) {
                Alist[i] = NULL;
            }
        }

        void insert(int src, int dstn);
        void display();
        void DFS(int src);
        void BFS(int src);
};

void Graph::insert(int src, int dstn) {
    Node* newNode = new Node(dstn);

    if (Alist[src] == NULL) {
        Alist[src] = newNode;
    } else {
        Node* temp = Alist[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Graph::display() {
    for (int i = 0; i < no_of_vertices; ++i) {
        Node* temp = Alist[i];
        cout << "Vertex " << i << ": ";
        while (temp != NULL) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void Graph::DFS(int src) {
    cout << "DFS is ";
    stack<int> s;
    bool visited[6] = {false, false, false, false, false, false};

    s.push(src);
    visited[src] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        cout << current << " ";

        Node* temp = Alist[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                s.push(temp->vertex);
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

void Graph::BFS(int src) {
    cout << "BFS is ";
    queue<int> q;
    bool visited[6] = {false, false, false, false, false, false};

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        Node* temp = Alist[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                q.push(temp->vertex);
                visited[temp->vertex] = true;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

int main() {
    Graph G1(6);
    G1.insert(0, 2);
    G1.insert(0, 5);
    G1.insert(0, 3);
    G1.insert(1, 3);
    G1.insert(2, 1);
    G1.insert(2, 4);
    G1.insert(3, 1);
    G1.insert(4, 3);
    G1.insert(4, 5);
    G1.insert(5, 1);
    G1.display();
    G1.DFS(0);
    G1.BFS(0);

    return 0;
}
