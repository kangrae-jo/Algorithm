#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int EMPTY = -2;
const int BLACK = -1;
const int RAINBOW = 0;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Group {
    int y = -1, x = -1;
    int normal = -1;
    int rainbow = -1;

    bool operator<(const Group& other) const {
        int b1 = normal + rainbow, b2 = other.normal + other.rainbow;
        if (b1 != b2) return b1 < b2;
        if (rainbow != other.rainbow) return rainbow < other.rainbow;
        if (normal != other.normal) return normal < other.normal;
        if (y != other.y) return y < other.y;
        return x < other.x;
    }
};

bool isIn(int y, int x, int N) { return 0 <= y && y < N && 0 <= x && x < N; }

Group getGroupSize(vector<vector<int>>& board, int y, int x, int color, int N, vector<vector<bool>>& v) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    Group group = {y, x, 0, 0};
    while (!q.empty()) {
        auto [curY, curX] = q.front();
        q.pop();

        if (board[curY][curX] == RAINBOW) group.rainbow++;
        else {
            v[curY][curX] = true;
            group.normal++;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nextY = curY + OFFSET[dir][0];
            int nextX = curX + OFFSET[dir][1];
            if (isIn(nextY, nextX, N) && !visited[nextY][nextX] &&
                (board[nextY][nextX] == color ||
                 board[nextY][nextX] == RAINBOW)) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
    }

    return group;
}

void eraseBlock(vector<vector<int>>& board, int y, int x, int color, int N) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        auto [curY, curX] = q.front();
        q.pop();

        board[curY][curX] = EMPTY;

        for (int dir = 0; dir < 4; dir++) {
            int nextY = curY + OFFSET[dir][0];
            int nextX = curX + OFFSET[dir][1];
            if (isIn(nextY, nextX, N) && !visited[nextY][nextX] &&
                (board[nextY][nextX] == color ||
                 board[nextY][nextX] == RAINBOW)) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
    }
}

void moveDown(vector<vector<int>>& board, int N) {
    for (int x = 0; x < N; x++) {
        for (int y = N - 2; y >= 0; y--) {
            if (board[y][x] != EMPTY && board[y][x] != BLACK) {
                int offset = 1;
                while (y + offset < N) {
                    if (board[y + offset][x] == EMPTY) offset++;
                    else break;
                }
                if (y + offset - 1 != y) {
                    board[y + offset - 1][x] = board[y][x];
                    board[y][x] = EMPTY;
                }
            }
        }
    }
}

vector<vector<int>> rotate(vector<vector<int>>& board, int N) {
    vector<vector<int>> rotated(N, vector<int>(N, EMPTY));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            rotated[abs(x - N + 1)][y] = board[y][x];
        }
    }
    return rotated;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
        }
    }

    int score = 0;
    while (true) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        Group largest;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x] && board[y][x] != BLACK &&
                    board[y][x] != EMPTY && board[y][x] != RAINBOW) {
                    Group temp = getGroupSize(board, y, x, board[y][x], N, visited);
                    if (largest < temp) largest = temp;
                }
            }
        }
        if (largest.normal == 0 || largest.normal + largest.rainbow < 2) break;

        score += (largest.normal + largest.rainbow) * (largest.normal + largest.rainbow);
        
        eraseBlock(board, largest.y, largest.x, board[largest.y][largest.x], N);
        moveDown(board, N);
        board = rotate(board, N);
        moveDown(board, N);
    }

    cout << score;

    return 0;
}
