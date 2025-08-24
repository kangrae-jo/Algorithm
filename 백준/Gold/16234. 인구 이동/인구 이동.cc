#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<vector<int>> board;
int N, L, R;

bool isIn(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

bool canOpen(int a, int b) {
    int diff = abs(a - b);
    return L <= diff && diff <= R;
}

bool move(vector<vector<bool>>& visited, int sY, int sX) {
    queue<pair<int, int>> q;
    q.push({sY, sX});
    visited[sY][sX] = true;

    queue<pair<int, int>> temp;
    int people = 0;
    bool isMoved = false;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        people += board[y][x];
        temp.push({y, x});

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(y_, x_) && !visited[y_][x_] && canOpen(board[y][x], board[y_][x_])) {
                q.push({y_, x_});
                visited[y_][x_] = true;
                isMoved = true;
            }
        }
    }

    int moved = people / temp.size();
    while (!temp.empty()) {
        auto [y, x] = temp.front();
        temp.pop();

        board[y][x] = moved;
    }

    return isMoved;
}

int main() {
    cin >> N >> L >> R;

    board = vector<vector<int>>(N, vector<int>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
        }
    }

    int answer = 0;
    while (true) {
        bool isMoved = false;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x] && move(visited, y, x)) {
                    isMoved = true;
                }
            }
        }
        if (!isMoved) break;
        else answer ++;
    }

    cout << answer << '\n';

    return 0;
}