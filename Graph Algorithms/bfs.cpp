#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjList[100];
bool visited[100];

int stepCount = 0;

void bfs(int startVertex) {
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;
    stepCount+=3;

    while (!q.empty()) {
        stepCount++;
        int u = q.front();
        q.pop();
        stepCount+=2;
        for (int v : adjList[u]) {
            stepCount+=2;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                stepCount+=2;
            }
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

    bfs(startVertex);

    cout << "Step count: " << stepCount << endl;

    return 0;
}
