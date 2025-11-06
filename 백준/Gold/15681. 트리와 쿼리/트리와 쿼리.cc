#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> subtree;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int count = 1;

    for (int next : graph[node]) {
        if (!visited[next]) count += dfs(next);
    }

    return subtree[node] = count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;

    graph.resize(N + 1);
    subtree.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(R);

    while (Q--) {
        int node;
        cin >> node;
        cout << subtree[node] << "\n";
    }

    return 0;
}
