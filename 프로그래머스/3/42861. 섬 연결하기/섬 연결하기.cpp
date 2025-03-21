#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionNodes(int a, int b) {
    parent[b] = a;
}

bool compareTo(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), compareTo);

    parent = vector<int> (n);
    for (int i = 0; i < n; i++) parent[i] = i;

    int answer = 0, edges = 0;
    for (auto &cost : costs) {
        int u = cost[0], v = cost[1], w = cost[2];
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            unionNodes(rootU, rootV);
            answer += w;
            edges++;
            if (edges == n - 1) break;
        }
    }
    return answer;
}