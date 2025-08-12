#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> tSort(vector<vector<int>>& graph, vector<int> indegree, int N) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    vector<int> result;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        result.push_back(cur);

        for (int next : graph[cur]) {
            if (--indegree[next] == 0) pq.push(next);
        }
    }

    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> indegree(N + 1, 0);
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }

    vector<int> answer = tSort(graph, indegree, N);
    for (int i : answer) cout << i << " ";

    return 0;
}