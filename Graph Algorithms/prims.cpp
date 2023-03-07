#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<pair<int, int>> prim(const vector<vector<pair<int, int>>>& adj, int source) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, weight] : adj[u]) {
            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                parent[v] = u;
                pq.emplace(weight, v);
            }
        }
    }

    vector<pair<int, int>> mst;
    for (int v = 0; v < n; v++) {
        if (parent[v] != -1) {
            mst.emplace_back(parent[v], v);
        }
    }

    return mst;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].emplace_back(v, weight);
    }

    vector<pair<int, int>> mst = prim(adj, 0);

    for (auto [u, v] : mst) {
        cout << u << " - " << v << endl;
    }

    return 0;
}
