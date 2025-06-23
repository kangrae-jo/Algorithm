#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;

long long dfs(int cur) {
    if (graph[cur].empty()) {
        return 0;
    }

    long long answer = 0;
    for (auto [next, w] : graph[cur]) {
        answer = max(answer, dfs(next) + w);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    graph = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int in, out, w;
        cin >> in >> out >> w;
        graph[in].push_back({out, w});
    }

    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        if (graph[i].empty()) continue;

        vector<long long> lengths;
        for (auto [child, w] : graph[i]) {
            lengths.push_back(dfs(child) + w);
        }

        sort(lengths.begin(), lengths.end(), greater<>());
        long long first = lengths.size() > 0 ? lengths[0] : 0;
        long long second = lengths.size() > 1 ? lengths[1] : 0;

        answer = max(answer, first + second);
    }

    cout << answer << endl;

    return 0;
}