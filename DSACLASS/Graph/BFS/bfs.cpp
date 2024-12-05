#include <iostream>
using namespace std;

// Function to perform BFS
void bfs(int graph[][100], int n, int start) {
    bool visited[100] = {false}; // To keep track of visited vertices
    int bfsArray[100];           // Array to simulate the queue
    int front = 0, rear = 0;     // Front and rear for managing the array

    // Mark the starting vertex as visited and enqueue it
    visited[start] = true;
    bfsArray[rear++] = start; // Enqueue the starting vertex

    cout << "BFS traversal starting from vertex " << start << ": ";

    // Process vertices while the array (queue) is not empty
    while (front < rear) {
        int current = bfsArray[front++]; // Dequeue
        cout << current << " ";         // Print the current vertex

        // Visit all adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) { // If there is an edge and it's unvisited
                visited[i] = true;         // Mark as visited
                bfsArray[rear++] = i;      // Enqueue the vertex
            }
        }
    }
    cout << endl;
}

int main() {
    int n, start;

    // Input the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Input the starting vertex
    cout << "Enter the starting vertex: ";
    cin >> start;

    // Call the BFS function
    bfs(graph, n, start);

    return 0;
}
