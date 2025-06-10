#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long>> FW(vector<vector<long long>> dist, int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> graph(n + 1, vector<long long>(n + 1, 1e11));
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    vector<vector<long long>> answer = FW(graph, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || answer[i][j] == 1e11) cout << "0 ";
            else cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}