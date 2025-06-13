#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dijkstra(const vector<vector<pair<int, int>>>& graph, int s, int e) {
    vector<int> dist(graph.size(), 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [c, v] = pq.top(); 
        pq.pop();

        if (dist[v] < c) continue;

        for (auto [v_, c_] : graph[v]) {
            if (dist[v_] > c + c_) {
                dist[v_] = c + c_;
                pq.push({dist[v_], v_});
            }
        }
    }
    
    return dist[e] == 1e9 ? -1 : dist[e];
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    int a1 = dijkstra(graph, 1, v1);
    int a2 = dijkstra(graph, v1, v2);
    int a3 = dijkstra(graph, v2, N);

    int b1 = dijkstra(graph, 1, v2);
    int b2 = dijkstra(graph, v2, v1);
    int b3 = dijkstra(graph, v1, N);

    int res1 = (a1 == -1 || a2 == -1 || a3 == -1) ? -1 : a1 + a2 + a3;
    int res2 = (b1 == -1 || b2 == -1 || b3 == -1) ? -1 : b1 + b2 + b3;
    
    if (res1 == -1 && res2 == -1) cout << -1;
    else cout << min(res1, res2);

    return 0;
}