#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool solution(const vector<vector<pair<int, int>>>& graph, int m, int s, int e) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int cur = q.front(); 
        q.pop();

        if (cur == e) return true;

        for (auto [next, dist] : graph[cur]) {
            if (!visited[next] && dist >= m) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    int s, e;
    cin >> s >> e;

    long long start = 1, end = 1000000000;
    while (start <= end) {
        long long mid = (start + end) / 2;
        if (solution(graph, mid, s, e)) start = mid + 1;
        else end = mid - 1;
    }

    cout << end;

    return 0;
}