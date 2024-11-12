#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Representing infinity

// Function to implement Dijkstra's algorithm
void dijkstra(int src, const vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[src] = 0;

    // Min-heap priority queue to select the vertex with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // Pair of (distance, vertex)

    while (!pq.empty()) {
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();

        // If the distance of u from the source in the queue is greater, skip it
        if (uDist > dist[u]) {
            continue;
        }

        // Explore neighbors
        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step: check if we can find a shorter path to v
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int vertices = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(vertices);

    // Example edges and weights
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 3});
    adj[1].push_back({2, 2});
    adj[1].push_back({4, 4});
    adj[2].push_back({3, 9});
    adj[3].push_back({2, 7});
    adj[4].push_back({1, 1});
    adj[4].push_back({2, 8});
    adj[4].push_back({3, 2});

    vector<int> dist;
    int source = 0; // Starting point

    dijkstra(source, adj, dist);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
