#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution (vector<vector<pair<int ,double>>>& graph, int N) {
	vector<bool> visited(N, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq; // cost, node
    pq.push({0.0, 0});
    
    double answer = 0;
    int cnt = 0;
    
    while (!pq.empty() && cnt < N) {
    	auto [cost, node] = pq.top();
        pq.pop();
        
        if (visited[node]) continue;
        visited[node] = true;
        answer += cost;
        cnt++;
        
        for (auto& next : graph[node]) {
            int node_ = next.first;
            double cost_ = next.second;
            if (!visited[node_]) {
                pq.push({cost_,node_});
            }
        }
    }
    return llround(answer);
}

int main(int argc, char** argv) {
	int T;
	cin>>T;
	
	for (int test_case = 1; test_case <= T; ++test_case) {
		int N;
        cin >> N;
        
        vector<pair<int, int>> nodes(N);
        for (int i = 0; i < N; i++) cin >> nodes[i].first;   // x
        for (int i = 0; i < N; i++) cin >> nodes[i].second;  // y
        
        double E;
        cin >> E;
        
        vector<vector<pair<int, double>>> graph(N);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                double dx = nodes[i].first - nodes[j].first;
                double dy = nodes[i].second - nodes[j].second;
                double dist = dx*dx + dy*dy;
                double cost = dist * E;
                graph[i].push_back({j, cost});
                graph[j].push_back({i, cost});
            }
        }
        
        long long answer = solution(graph, N);
        cout << "#" << test_case << " " << answer << '\n';
	}
    
	return 0;
}