#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<int> result;

void bfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int a, int b, int n, int m){
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[b][a] = true;
    
    int minX = a;
    int maxX = a;
    
    int cnt = 1;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++){
            int x_ = x + offset[dir][1];
            int y_ = y + offset[dir][0];
            if (0 <= x_ && x_ < m && 0 <= y_ && y_ < n && !visited[y_][x_] && land[y_][x_] == 1){
                visited[y_][x_] = true;
                q.push({x_,y_});
                cnt++;
                maxX = max(maxX, x_);
            }
        }
    }
    
    for (int i = minX; i <= maxX; i++) result[i] += cnt;
}

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    result = vector<int> (m, 0);
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            if (!visited[y][x] && land[y][x] != 0) 
                bfs(land, visited, x, y, n, m);
        }
    }
    
    return *max_element(result.begin(), result.end());
}