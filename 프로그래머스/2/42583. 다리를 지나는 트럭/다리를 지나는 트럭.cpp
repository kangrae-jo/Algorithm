#include <queue>
#include <vector>

using namespace std;

void pass(queue<pair<int, int>>& q, int time, int& total) {
    while (!q.empty() && q.front().second == time) {
        total -= q.front().first;
        q.pop();
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge;
    int time = 0;
    int totalWeight = 0;

    for (int truck : truck_weights) {
        // 지나간 트럭 큐에서 제거
        pass(bridge, time, totalWeight);

        // 더 지나갈 수 없을 때 시간 점프
        while (totalWeight + truck > weight) {
            time = bridge.front().second;
            pass(bridge, time, totalWeight);
        }

        // 건너기 시도
        bridge.push({truck, time + bridge_length});
        totalWeight += truck;
        time++;
    }

    return bridge.back().second + 1;
}