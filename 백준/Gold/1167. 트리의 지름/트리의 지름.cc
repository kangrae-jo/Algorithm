#include <iostream>
#include <vector>

using namespace std;

int V;
vector<vector<pair<int, int>>> graph;

pair<int,int> solution(vector<bool>& v, int cur) {
    int answer = 0;
    int node = cur;

    for (auto [next, w] : graph[cur]) {
        if (v[next]) continue;
        v[next] = true;

        auto [candiW, candiN] = solution(v, next);
        if (answer < candiW + w) {
            answer = candiW + w;
            node = candiN;
        }
    }
    return {answer, node};
}

int main() {
    cin >> V;

    graph = vector<vector<pair<int, int>>>(V + 1);
    for (int i = 1; i <= V; i++) {
        int a, b, w;
        cin >> a;

        while (cin >> b && b != -1) {
            cin >> w;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }
    }

    vector<bool> visited(V + 1, false);
    visited[1] = true;
    auto [weigth, node] = solution(visited, 1);

    visited.assign(V + 1, false);
    visited[node] = true;
    cout << solution(visited, node).first;

    return 0;
}