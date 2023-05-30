#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Graph edge structure
struct Edge {
    int destination;
    int weight;
};

// Function to perform Dijkstra's algorithm
void dijkstraAlgorithm(const vector<vector<Edge>>& graph, int source, vector<int>& distances) {
    int numVertices = graph.size();
    distances.resize(numVertices, numeric_limits<int>::max()); // Initialize distances with infinity
    distances[source] = 0; // Distance from source to itself is 0

    // Priority queue to store vertices based on their minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // If there is a shorter path to v through u
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    int numVertices = 6;
    vector<vector<Edge>> graph(numVertices);

    // Add edges to the graph (example)
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 15});
    graph[0].push_back({5, 5});
    graph[1].push_back({0, 10});
    graph[1].push_back({3, 30});
    graph[1].push_back({2, 10});
    graph[2].push_back({1, 10});
    graph[2].push_back({3, 12});
    graph[2].push_back({4, 5});
    graph[3].push_back({2, 12});
    graph[3].push_back({1, 30});
    graph[3].push_back({5, 20});
    graph[4].push_back({0, 15});
    graph[4].push_back({2, 5});
    graph[5].push_back({0, 5});
    graph[5].push_back({3, 20});

    int source = 5;
    vector<int> distances;

    dijkstraAlgorithm(graph, source, distances);

    // Print the shortest distances from the source

    cout << "Selected Source : " << source << endl;
    int total = 0;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Distance from " << source << " to " << i << ": " << distances[i] << endl;
        total += distances[i];
    }

    double avg = total/5.0;
    cout << "Average time to reach a town : " << avg << " hours" <<endl;

    return 0;
}