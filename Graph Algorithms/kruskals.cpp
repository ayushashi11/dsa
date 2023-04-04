#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

bool all_true(const vector<bool>& v) {
    for (bool b : v) {
        if (!b) return false;
    }
    return true;
}

struct edge {
    int u, v, weight;
    edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

vector<edge> kruskal(const vector<vector<edge>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    priority_queue<edge> pq;
    for (auto e : adj[0]) {
        pq.push(e);
    }
    visited[0] = true;

    vector<edge> mst;
    while (!pq.empty() && !all_true(visited)) {
        edge e = pq.top();
        pq.pop();
        if (visited[e.v]) continue;
        visited[e.v] = true;
        mst.push_back(e);
        for (auto e : adj[e.v]) {
            pq.push(e);
        }
    }

    return mst;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].emplace_back(*new edge(u, v, weight));
    }

    vector<edge> mst = kruskal(adj);

    for (auto e : mst) {
        cout << e.u << " - " << e.v << endl;
    }

    return 0;
}
