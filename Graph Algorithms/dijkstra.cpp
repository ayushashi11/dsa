#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj, int source) {
    int n = adj.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, weight] : adj[u]) {
            int new_dist = dist[u] + weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    return dist;
}

int main() {
    int n, m, source;
    cin >> n >> m >> source;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].emplace_back(v, weight);
    }

    vector<int> dist = dijkstra(adj, source);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "No path from " << source << " to " << i << endl;
        } else {
            cout << "Shortest path from " << source << " to " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}
