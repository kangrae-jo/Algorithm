#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<pair<int, int>>>& graph, int s, int N) {
    vector<int> dist(N + 1, 1e9);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;  // {t, v}
    pq.push({0, s});

    while (!pq.empty()) {
        auto [t, v] = pq.top();
        pq.pop();

        if (t > dist[v]) continue;
        for (auto [v_, t_] : graph[v]) {
            int newDist = t + t_;
            if (newDist > dist[v_]) continue;
            dist[v_] = newDist;
            pq.push({newDist, v_});
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
    }

    vector<int> back = solution(graph, X, N);
    vector<int> gogo;

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        gogo = solution(graph, i, N);
        answer = max(answer, gogo[X] + back[i]);
    }

    cout << answer;

    return 0;
}