#include <iostream>
#include <vector>

using namespace std;

vector<int> adjList[100];
bool visited[100];

int stepCount = 0;

bool dfs(int u) {
    stepCount++;
    if(visited[u]) return true;
    visited[u] = true;
    stepCount++;
    for (int v : adjList[u]) {
        stepCount++;
        stepCount++;
        if (!visited[v]) {
            stepCount++;
            if(dfs(v)){
                stepCount++;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    int startVertex, endVertex;
    cin >> startVertex;

    if(!dfs(startVertex)) cout<<"no ";
    cout<<"cycles exist"<<endl;

    cout << "Step count: " << stepCount << endl;

    return 0;
}
