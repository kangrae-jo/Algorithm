#include <vector>
#include <queue>

using namespace std;

const int offset[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
const int WALL = 0;
const int PATH = 1;

bool isMoveable(vector<vector<int>>& maps, int y, int x, int n, int m){
    return 0<=y && y<n && 0<=x && x<m && maps[y][x] == PATH;
}

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    
    int answer = 1;
    while (!q.empty()){
        int size = q.size();
        while(size--){
            auto [y, x] = q.front();
            q.pop();
            
            if (y == n-1 && x == m-1) return answer;
            
            for (int dir=0; dir<4; dir++){
                int y_ = y + offset[dir][0];
                int x_ = x + offset[dir][1];
                if (isMoveable(maps, y_ , x_, n, m) && !visited[y_][x_]){
                    q.push({y_, x_});
                    visited[y_][x_] = true;
                }
            }
        }
        answer++;     
    }
    
    return -1;
}