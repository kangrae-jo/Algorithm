#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    if (visited[node]) return 0;
    queue<int> q;
    q.push(node);
    visited[node] = true;

    int cnt = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> knows(K);
    for (int i = 0; i < K; i++) {
        cin >> knows[i];
    }

    vector<vector<int>> graph(N + 1);
    vector<vector<int>> teams(M);
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;

        teams[i].resize(t);
        for (int x = 0; x < t; x++) {
            cin >> teams[i][x];
        }

        for (int x = 0; x < t; x++) {
            for (int y = 0; y < x; y++) {
                if (teams[i][x] == teams[i][y]) continue;
                graph[teams[i][x]].push_back(teams[i][y]);
                graph[teams[i][y]].push_back(teams[i][x]);
            }
        }
    }

    int knowCnt = 0;
    vector<bool> visited(N + 1);
    for (int know : knows) {
        knowCnt += bfs(graph, know, visited);
    }

    int answer = 0;
    for (auto team : teams) {
        bool flag = false;
        for (int t : team) {
            if (visited[t]) flag = true;
        }
        if (!flag) answer++;
    }

    cout << answer;

    return 0;
}