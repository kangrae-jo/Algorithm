#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9;

struct OUTIN{
    int out, in;
};

map <int, OUTIN> outin;
map <int, vector<int>> graph;

int findStartV(int N){
    for (int v=1; v<=N; v++) if (outin[v].in == 0 && outin[v].out >= 2) return v;
}

int dfs(int v, vector<bool>& visited){
    visited[v] = true;
    
    int out = outin[v].out;
    if (out == 0) return INF;

    for (int next : graph[v]){
        if (!visited[next]) out = max(out, dfs(next, visited));
    }
    return out;
}

vector<int> solution(vector<vector<int>> edges) {
    int N = 0;
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        outin[edge[0]].out++;
        outin[edge[1]].in++;
        N = max({N, edge[0], edge[1]});
    }
    
    int start_v = findStartV(N);    
    vector<bool> visited(N+1, false);
    vector<int> answer(4, 0);
    answer[0] = start_v;
    
    for (int v : graph[start_v]) {
        int result = dfs(v, visited);
        if (result == INF) answer[2]++;
        else if (result == 1) answer[1]++;
        else answer[3]++;
    }
    
    return answer;
}