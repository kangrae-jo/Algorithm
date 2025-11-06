#include <queue>
#include <vector>

using namespace std;

const int CONNECTED = 1;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {  
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && computers[i][j] == CONNECTED) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, graph, visited);
            answer++;
        }
    }
    
    return answer;
}