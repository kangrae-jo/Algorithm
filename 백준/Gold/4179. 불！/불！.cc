#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const char WALL = '#';
const char PATH = '.';
const char START = 'J';
const char FIRE = 'F';
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int R, C;
pair<int, int> start;
vector<vector<int>> fireTime;
vector<pair<int, int>> fireInit;

bool isIn(int y, int x) { return 0 <= y && y < R && 0 <= x && x < C; }

void diffuse(vector<string>& board) {
    fireTime.assign(R, vector<int>(C, 1e9));
    
    queue<pair<int, int>> q;
    for (auto [y, x] : fireInit) {
        fireTime[y][x] = 0;
        q.push({y, x});
    }

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(y_, x_) && board[y_][x_] != WALL && fireTime[y_][x_] > fireTime[y][x] + 1) {
                fireTime[y_][x_] = fireTime[y][x] + 1;
                q.push({y_, x_});
            }
        }
    }
}

int solution(vector<string>& board) {
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    visited[start.first][start.second] = true;

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        time++;
        while (size--) {
            auto [y, x] = q.front();
            q.pop();

            if (y == 0 || y == R - 1 || x == 0 || x == C - 1) return time;

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];
                if (isIn(y_, x_) && board[y_][x_] == PATH && fireTime[y_][x_] > time && !visited[y_][x_]) {
                    q.push({y_, x_});
                    visited[y_][x_] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> R >> C;

    vector<string> board(R);
    for (int y = 0; y < R; y++) {
        cin >> board[y];
        for (int x = 0; x < C; x++) {
            if (board[y][x] == START) start = {y, x};
            else if (board[y][x] == FIRE) fireInit.push_back({y, x});
        }
    }

    diffuse(board);

    int answer = solution(board);
    if (answer == -1) cout << "IMPOSSIBLE\n";
    else cout << answer << "\n";

    return 0;
}