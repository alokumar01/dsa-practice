#include <iostream>
using namespace std;

// Function to implement Floyd-Warshall Algorithm
void floydWarshall(int graph[][100], int n) {
    int dist[100][100];
    const int INF = 9999; // Large value to represent no direct connection

    // Step 1: Initialize distance matrix from the input graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j]; // Copy graph weights to distance matrix
        }
    }

    // Step 2: Update distances using each vertex as an intermediate vertex
    for (int k = 0; k < n; k++) {             // Intermediate vertex
        for (int i = 0; i < n; i++) {         // Source vertex
            for (int j = 0; j < n; j++) {     // Destination vertex
                // Update distance if a shorter path is found through vertex k
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print the shortest distance matrix
    cout << "Shortest distances between vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    // Step 1: Take number of vertices as input
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100];
    const int INF = 9999; // Large value to represent no direct connection

    // Step 2: Take adjacency matrix input
    cout << "Enter the adjacency matrix (use " << INF << " for no direct connection):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Step 3: Call the Floyd-Warshall function
    floydWarshall(graph, n);

    return 0;
}
