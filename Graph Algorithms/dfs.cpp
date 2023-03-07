#include <iostream>
#include <vector>

using namespace std;

vector<int> adjList[100];
bool visited[100];

int stepCount = 0;

void dfs(int u) {
    if(visited[u]) return;
    visited[u] = true;
    stepCount++;

    for (int v : adjList[u]) {
        stepCount++;
        stepCount++;
        if (!visited[v]) {
            stepCount++;
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int startVertex;
    cin >> startVertex;

    dfs(startVertex);

    cout << "Step count: " << stepCount << endl;

    return 0;
}
