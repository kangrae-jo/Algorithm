#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long prim(int start, vector<vector<pair<int,int>>>& graph, int V) {
    vector<bool> visited(V + 1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0, start});
    long long total = 0;

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;
        total += cost;

        for (auto& [nextCost, nextNode] : graph[node]) {
            if (!visited[nextNode]) {
                pq.push({nextCost, nextNode});
            }
        }
    }
    return total;
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {

        int V, E;
        cin >> V >> E;

        vector<vector<pair<int,int>>> graph(V + 1);

        for (int i = 0; i < E; i++) {
            int A, B, C;
            cin >> A >> B >> C;

            graph[A].push_back({C, B}); // cost, node
            graph[B].push_back({C, A});
        }

        long long answer = prim(1, graph, V);
        cout << "#" << test_case << " " << answer << "\n";
    }

    return 0;
}