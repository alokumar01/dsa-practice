#include <iostream>
using namespace std;

void warshallAlgorithm(int graph[][100], int n) {
    int reach[100][100];

    // copying original path to reach
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    // update reach matrix using warshall algo
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // print 
    cout << "Transitive closure of the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
};


int main() {
    int n;
    cout << "enter the number of vertices: ";
    cin >> n;

    int graph[100][100];

    cout << "adjacency matric 1 for edges, 0 for no edges:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    warshallAlgorithm(graph, n);
    return 0;
}