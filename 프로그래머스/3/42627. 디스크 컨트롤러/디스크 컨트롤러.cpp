#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int sum = 0, time = 0, index = 0;
    int n = jobs.size();

    while (index < n || !pq.empty()) {
        // 밀려있는 작업 push
        while (index < n && jobs[index][0] <= time) {
            pq.push({jobs[index][1], jobs[index][0]});
            index++;
        }

        if (!pq.empty()) {
            auto [t, s] = pq.top();
            pq.pop();

            time += t;
            sum += time - s;        // 대기 시간 + 실행 시간 합산
        } 
        else time = jobs[index][0]; // 다음 작업의 요청 시각으로 점프
    }

    return sum / n;
}