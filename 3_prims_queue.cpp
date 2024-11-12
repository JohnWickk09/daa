#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

void primsAlgorithm(int n, vector<vector<pii>>& adjList) {
    vector<int> key(n, INT_MAX);        // Store minimum edge weight to reach each vertex
    vector<bool> inMST(n, false);       // Track vertices included in MST
    vector<int> parent(n, -1);          // Store MST structure
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap to select edge with min weight

    key[0] = 0;                         // Start from the first vertex
    pq.push({0, 0});                    // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;        // Get vertex with minimum key value
        pq.pop();

        inMST[u] = true;                // Include u in MST

        for (auto [weight, v] : adjList[u]) { // For each adjacent vertex v of u
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Output MST edges
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << key[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adjList(n); // Adjacency list representation of graph

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({weight, v});
        adjList[v].push_back({weight, u});
    }

    primsAlgorithm(n, adjList);

    return 0;
}
