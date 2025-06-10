#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> stones(N);
    for (int i = 0; i < N; i++) cin >> stones[i].first >> stones[i].second;
    sort(stones.begin(), stones.end());

    vector<int> bags(K);
    for (int i = 0; i < K; i++) cin >> bags[i];
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long answer = 0;
    int index = 0;

    for (int i = 0; i < K; i++) {
        // 현재 가방에 들어갈 수 있는 모든 보석을 pq에 push
        while (index < N && stones[index].first <= bags[i]) pq.push(stones[index++].second);        
        
        // pq에서 가장 가치 큰 보석 담기
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << endl;

    return 0;
}