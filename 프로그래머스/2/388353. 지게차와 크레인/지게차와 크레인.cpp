#include <string>
#include <vector>
#include <queue>

using namespace std;

const int EMPTY = 0;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vector<vector<int>> board;

bool isIn(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }
bool isOutLine(int y, int x) { return y == 0 || y == n - 1 || x == 0 || x == m - 1; }

bool canRemove(int y, int x, int c){
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    
    while (!q.empty()) {
        auto [curY, curX] = q.front();
        q.pop();
        
        if (isOutLine(curY, curX)) return true;
        
        for (int dir = 0; dir < 4; dir++) {
            int nextY = curY + OFFSET[dir][0];
            int nextX = curX + OFFSET[dir][1];
            
            if (isIn(nextY, nextX) && board[nextY][nextX] == EMPTY && !visited[nextY][nextX]) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
    }
    
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    
    board = vector<vector<int>> (n, vector<int> (m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            board[y][x] = storage[y][x];
        }
    }
    
    for (string request : requests) {
        int c = request[0];
        
        if (request.size() == 2) {      // all
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    if (board[y][x] == c) board[y][x] = EMPTY;
                }
            }
        } else {
            vector<pair<int, int>> result;
            for (int y = 0; y < n; y++) {   // outline
                for (int x = 0; x < m; x++) {
                    if (board[y][x] == c && canRemove(y, x, c)) result.push_back({y, x});
                }
            }
    
            for (auto [y, x] : result) board[y][x] = EMPTY;
        }
    }
    
    int answer = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (board[y][x] != EMPTY) answer++;
        }
    }
        
    return answer;
}