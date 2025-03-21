#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

bool compareTo(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    parent = vector<int> (n);
    for (int i = 0; i < n; i++) parent[i] = i;

    sort(costs.begin(), costs.end(), compareTo);
    
    int answer = 0;
    for (auto &cost : costs) {
        int rootU = findParent(cost[0]), rootV = findParent(cost[1]);
        if (rootU != rootV) {
            parent[rootV] = rootU;
            answer += cost[2];
        }
    }
    return answer;
}
