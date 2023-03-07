#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 100;

vector<int> adjList[MAX_V];
bool visited[MAX_V];

int stepCount = 0;

void dfs(int u) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            dfs(v);
            stepCount++;
        }
        stepCount++;
    }
}

bool isConnected(int n) {
    dfs(1);
    stepCount+=2;
    for (int i = 1; i <= n; i++) {
        stepCount+=2;
        if (!visited[i]) {
            stepCount++;
            return false;
        }
    }
    stepCount++;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    if (isConnected(n)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    cout << "Step count: " << stepCount << endl;

    return 0;
}
