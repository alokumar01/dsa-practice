#include <iostream>
using namespace std;

void dfs(int graph[][100], bool visited[], int n, int start) {
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, visited, n, i);
        }
    }
}


int main() {
    int n, start;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int graph[100][100];
    cout << "Enter the adjacency matrix: \n";
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> start;

    bool visited[100] = false;

    cout << "DFS traversal starting from vertex " << start << ": ";

    dfs(graph, visited, n, start);

    return 0;
}