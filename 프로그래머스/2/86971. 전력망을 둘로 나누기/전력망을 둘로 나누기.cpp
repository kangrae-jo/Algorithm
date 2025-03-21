#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    int cnt = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
            cnt++;
        }
    } 
    return cnt;
}

int cutWire(vector<vector<int>> graph, int a, int b) {
    graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
    graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

    return bfs(graph);
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n);
    for (auto wire : wires) {
        graph[wire[0] - 1].push_back(wire[1] - 1);
        graph[wire[1] - 1].push_back(wire[0] - 1);
    }
    
    int answer = n;
    for (auto wire : wires) {
        int zone1 = cutWire(graph, wire[0] - 1, wire[1] - 1);
        int zone2 = n - zone1;
        answer = min({answer, abs(zone1 - zone2)});
    }
    
    return answer;
}