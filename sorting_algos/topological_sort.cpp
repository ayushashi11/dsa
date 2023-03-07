#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int stepCount = 0;

void topologicalSort(vector<vector<int>>& adj, vector<int>& indegree, vector<int>& result) {
    int n = adj.size();
    queue<int> q;
    
    // Initialize queue with vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            stepCount++;
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        stepCount++;
        
        // Decrease indegree of adjacent vertices
        for (int v : adj[u]) {
            indegree[v]--;
            stepCount++;
            
            // Add vertices with indegree 0 to the queue
            if (indegree[v] == 0) {
                q.push(v);
                stepCount++;
            }
        }
    }
    
    // Check for cycle
    if (result.size() != n) {
        cout << "The graph contains a cycle\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    vector<int> result;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    topologicalSort(adj, indegree, result);
    
    cout << "Topological sort order: ";
    for (int u : result) {
        cout << u << " ";
    }
    cout << endl;
    cout << "Step count: " << stepCount << endl;
    
    return 0;
}
