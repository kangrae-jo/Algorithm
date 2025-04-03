#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool test(vector<int> weak, vector<int> dist, int n) {
    int weakLen = weak.size();
    for (int i = 0; i < weakLen; i++) weak.push_back(weak[i] + n); // 원형 구현
    
    for (int start = 0; start < weakLen; start++) {
        int covered = start; // 현재까지 커버한 weak 인덱스
        for (int i = 0; i < dist.size(); i++) {
            int reach = weak[covered] + dist[i]; // 현재 친구가 점검할 수 있는 최대 거리

            while (covered < start + weakLen && weak[covered] <= reach) covered++;
            if (covered >= start + weakLen) return true;
        }
    }

    return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9;
    sort(dist.begin(), dist.end());
    
    // 각 조합에서 보내야 하는 친구 최소값을 answer에 담기, 다음 순열로 이동
    do {
        for (int i = 1; i <= dist.size(); i++) {
            vector<int> selected(dist.begin(), dist.begin() + i);
            if (test(weak, selected, n)) {
                answer = min(answer, i);
                break;
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));

    if (answer == 9) return -1;
    return answer;
}