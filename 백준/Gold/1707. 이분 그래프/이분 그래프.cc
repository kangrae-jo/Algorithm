#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int startNode, vector<vector<int>>& graph, vector<int>& colors) {
    queue<int> q;
    q.push(startNode);
    colors[startNode] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        int curColor = colors[cur];
        int nextColor = (curColor + 1) % 2;
        
        for (int next : graph[cur]) {
            if (colors[next] == -1) {
                colors[next] = nextColor;
                q.push(next);
            } 
            else if (colors[next] != nextColor) {
                return false;
            }
        }
    }
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while (K--) {
        int V, E;
        cin >> V >> E;
        
        vector<vector<int>> graph(V + 1);
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> colors(V + 1, -1);
        bool flag = true;
       
        for (int node = 1; node <= V; node++) {
            if (colors[node] == -1) {
                if (!bfs(node, graph, colors)) {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
