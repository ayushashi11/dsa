#include <iostream>
#include <vector>

using namespace std;

vector<int> adjList[100];
bool visited[100];

int stepCount = 0;

bool dfs(int u, int end) {
    stepCount++;
    if(visited[u]) return false;
    visited[u] = true;
    stepCount+=2;
    if(u==end){
        cout<<end<<endl;
        stepCount+=2;
        return true;
    }
    for (int v : adjList[u]) {
        stepCount++;
        stepCount++;
        if (!visited[v]) {
            stepCount++;
            if(dfs(v, end)){
                cout<<u<<endl;
                stepCount+=2;
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

    if(!dfs(startVertex, endVertex)) cout<<"No path exists"<<endl;

    cout << "Step count: " << stepCount << endl;

    return 0;
}
