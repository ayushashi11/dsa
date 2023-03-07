#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 100;

int adj[MAX_V][MAX_V];
int transpose[MAX_V][MAX_V];

int stepCount = 0;

void transposeGraph(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            transpose[j][i] = adj[i][j];
            stepCount++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    transposeGraph(n);

    cout << "Step count: " << stepCount << endl;

    return 0;
}
