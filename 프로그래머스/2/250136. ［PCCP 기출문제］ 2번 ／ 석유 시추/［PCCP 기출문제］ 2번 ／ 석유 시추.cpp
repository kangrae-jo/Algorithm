#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int EMPTY = 0;
const int OIL = 1;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N, M;
vector<int> result;

bool isIn(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

void bfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[b][a] = true;
    
    int minX = a;
    int maxX = a;
    
    int cnt = 1;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++){
            int x_ = x + OFFSET[dir][1];
            int y_ = y + OFFSET[dir][0];
            if (isIn(y_, x_) && !visited[y_][x_] && land[y_][x_] == OIL){
                q.push({x_,y_});
                visited[y_][x_] = true;
                cnt++;
                maxX = max(maxX, x_);
            }
        }
    }
    
    for (int i = minX; i <= maxX; i++) result[i] += cnt;
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();
    
    vector<vector<bool>> visited(N, vector<bool> (M, false));
    result = vector<int> (M, 0);
    for (int x = 0; x < M; x++){
        for (int y = 0; y < N; y++){
            if (!visited[y][x] && land[y][x] != EMPTY) 
                bfs(land, visited, x, y);
        }
    }
    
    return *max_element(result.begin(), result.end());
}