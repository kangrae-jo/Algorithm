#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    int answer = 0;
    int start = 1, end = distance;
    
    // 파라메트릭 서치
    // 1. 최소 거리를 정하기
    // 2. 정한 최소 거리보다 작은 애들은 삭제
    // 3. 삭제가 너무 많이 되면 최소거리 줄이기
    // 4. 아니라면 지금까지 최대인 최소 거리를 저장하고 최소 거리 늘려보기
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int remove = 0, prev = 0;
        
        for (int rock : rocks) {
            if (rock - prev < mid) remove++;
            else prev = rock;
        }
        
        if (remove > n) end = mid - 1;
        else {
            answer = mid;
            start = mid + 1;
        }        
    }

    return answer;
}