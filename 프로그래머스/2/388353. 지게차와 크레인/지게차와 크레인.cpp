#include <string>
#include <vector>
#include <queue>

#define EMPTY 0

using namespace std;

int n, m;
vector<vector<int>> board;
int offset[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool canRemove(int y, int x, int c){
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = false;
    
    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        
        if (cur_y == 0 || cur_y == n-1 || cur_x == 0 || cur_x == m-1) return true;
        
        for (int dir=0; dir<4; dir++) {
            int next_y = cur_y + offset[dir][0];
            int next_x = cur_x + offset[dir][1];
            
            if (0 <= next_y && next_y < n && 0 <= next_x && next_x < m 
                && board[next_y][next_x] == EMPTY && !visited[next_y][next_x]) {
                q.push({next_y, next_x});
                visited[next_y][next_x] = true;
            }
        }
    }
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    
    board = vector<vector<int>> (n, vector<int> (m));
    for (int y=0; y<n; y++) for (int x=0; x<m; x++) 
        board[y][x] = storage[y][x];
    
    for (string request : requests) {
        int c = request[0];
        if (request.size() == 2) {
            for (int y=0; y<n; y++) for (int x=0; x<m; x++)
                if (board[y][x] == c) board[y][x] = EMPTY;
        }
        else {
            vector<pair<int, int>> result;
            for (int y=0; y<n; y++) for (int x=0; x<m; x++)
                if (board[y][x] == c && canRemove(y, x, c)) result.push_back({y, x});

            for (auto [y, x] : result) board[y][x] = EMPTY;
        }
    }
    
    int answer = 0;
    for (int y=0; y<n; y++) for (int x=0; x<m; x++) 
        if (board[y][x] != EMPTY) answer++;
        
    return answer;
}