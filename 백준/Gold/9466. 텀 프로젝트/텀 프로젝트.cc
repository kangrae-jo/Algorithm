#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;
vector<bool> visited;
vector<bool> done;
int cnt;

void dfs(int cur) {
    visited[cur] = true;
    int next = graph[cur];

    if (!visited[next]) dfs(next);
    else if (!done[next]) {
        cnt++;
        for (int temp = next; temp != cur; temp = graph[temp]) {
            cnt++;
        }
    }
    done[cur] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        graph = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> graph[i];
        }

        cnt = 0;
        visited = vector<bool>(n + 1, false);
        done = vector<bool>(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }

        cout << n - cnt << '\n';
    }
    return 0;
}