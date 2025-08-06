#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

int N, M, K;
vector<vector<pair<int, int>>> graph;
vector<long long> distances;

void solution(vector<int>& places) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    distances.assign(N + 1, INF);

    for (int src : places) {
        pq.push({0, src});
        distances[src] = 0;
    }

    while (!pq.empty()) {
        auto [dist, cur] = pq.top(); 
        pq.pop();

        if (dist > distances[cur]) continue;

        for (auto [next, dist_] : graph[cur]) {
            long long newDist = dist + dist_;
            if (newDist < distances[next]) {
                distances[next] = newDist;
                pq.push({newDist, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    graph = vector<vector<pair<int, int>>>(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V, C;
        cin >> U >> V >> C;
        graph[V].push_back({U, C});
    }

    vector<int> places(K);
    for (int i = 0; i < K; i++) {
        cin >> places[i];
    }

    solution(places);

    int answer = 1;
    for (int i = 2; i <= N; i++) {
        if (distances[i] > distances[answer]) answer = i;
    }

    cout << answer << '\n' << distances[answer] << '\n';

    return 0;
}