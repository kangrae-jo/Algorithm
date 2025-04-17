#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
const int EMPTY = 0;
const int WALL = 1;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int HORSE[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int K, W, H;
vector<vector<int>> board;

struct Pos {
    int x, y, k; // 좌표와 남은 말 이동 횟수
};

bool isIn(int x, int y) {
    return 0 <= x && x < W && 0 <= y && y < H;
}

int bfs() {
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(K + 1, INF)));
    queue<Pos> q;

    dist[0][0][K] = 0;
    q.push({0, 0, K});

    while (!q.empty()) {
        auto [x, y, k] = q.front(); q.pop();
        int curDist = dist[y][x][k];

        if (x == W - 1 && y == H - 1) return curDist;
        for (int d = 0; d < 4; d++) {
            int nx = x + OFFSET[d][1];
            int ny = y + OFFSET[d][0];
            if (isIn(nx, ny) && board[ny][nx] == EMPTY && dist[ny][nx][k] > curDist + 1) {
                dist[ny][nx][k] = curDist + 1;
                q.push({nx, ny, k});
            }
        }

        if (k > 0) {
            for (int d = 0; d < 8; d++) {
                int nx = x + HORSE[d][1];
                int ny = y + HORSE[d][0];
                if (isIn(nx, ny) && board[ny][nx] == EMPTY && dist[ny][nx][k - 1] > curDist + 1) {
                    dist[ny][nx][k - 1] = curDist + 1;
                    q.push({nx, ny, k - 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> K >> W >> H;
    board.assign(H, vector<int>(W));
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            cin >> board[y][x];

    cout << bfs() << "\n";

    return 0;
}