#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> D(N + 1), indegree(N + 1, 0), dp(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
        }

        vector<vector<int>> graph(N + 1);
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }

        int W;
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++){
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = D[i];
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                if (dp[next] < dp[cur] + D[next]) dp[next] = dp[cur] + D[next];
                if (--indegree[next] == 0) q.push(next);
            }
        }

        cout << dp[W] << '\n';
    }

    return 0;
}