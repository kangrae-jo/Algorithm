#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<vector<int>> graph(17);
vector<int> info_;

void dfs(vector<int> notVisited, int cur, int sheep, int wolf) {
    if (info_[cur] == 0) sheep++;
    else wolf++;
    
    if (sheep <= wolf) return;
    answer = max(answer, sheep);

    // add cur's child 
    notVisited.insert(notVisited.end(), graph[cur].begin(), graph[cur].end());
    // remove cur
    auto new_end = remove(notVisited.begin(), notVisited.end(), cur);
    notVisited.erase(new_end, notVisited.end());
    // visit
    for (int next : notVisited) {
        dfs(notVisited, next, sheep, wolf);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    info_ = info;
    for (auto& edge : edges) graph[edge[0]].push_back(edge[1]);

    vector<int> notVisited = {0};
    dfs(notVisited, 0, 0, 0);
    
    return answer;
}
