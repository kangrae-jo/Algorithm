#include <queue>
#include <vector>
#include <tuple>

using namespace std;

const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isIn(int y, int x, int N) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int solution(vector<vector<int>> land, int height) {
    int N = land.size();
    vector<vector<bool>> visited(N, vector<bool> (N, false));
    
    int answer = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 0, 0});
    
    while(!pq.empty()) {
        auto [diff, y, x] = pq.top();
        pq.pop();
        
        if (visited[y][x]) continue;
        visited[y][x] = true;

        answer += diff;
        
        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(y_, x_, N) && !visited[y_][x_]) {
                int diff_ = abs(land[y_][x_] - land[y][x]);
                if (diff_ <= height) diff_ = 0;
                pq.push({diff_, y_, x_});
            }
        }    
    }
    
    return answer;
}