#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologySort(vector<vector<int>>& graph, vector<int>& indegree, int N) {
    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        result.push_back(cur);
        
        for (int next : graph[cur]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }

    if (result.size() != N) cout << 0 << '\n';
    else for (int x : result) cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);
    
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (num == 0) continue; 

        int from, to;
        cin >> from;
        
        for (int j = 0; j < num - 1; j++) {
            cin >> to;
            graph[from].push_back(to);
            indegree[to]++;
            from = to;
        }
    }
   
    topologySort(graph, indegree, N);

    return 0;
}