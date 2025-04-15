#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

const char PATH = '0';
const char WALL = '1';
const int OFFSET[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M;
vector<string> board;

int bfs() {
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    queue<tuple<int, int, int, int>> q; // y, x, dist, broken

    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto [y, x, dist, broken] = q.front();
        q.pop();

        if (y == N - 1 && x == M - 1) return dist;

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];

            if (y_ < 0 || x_ < 0 || y_ >= N || x_ >= M) continue;
            if (board[y_][x_] == PATH && !visited[y_][x_][broken]) {
                visited[y_][x_][broken] = true;
                q.push({y_, x_, dist + 1, broken});
            }
            else if (board[y_][x_] == WALL && !broken && !visited[y_][x_][broken]) {
                visited[y_][x_][broken] = true;
                q.push({y_, x_, dist + 1, broken + 1}); 
            }
        }
    }

    return -1; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    board.resize(N);
    for (int i = 0; i < N; i++) 
        cin >> board[i];

    cout << bfs() << "\n";

    return 0;
}