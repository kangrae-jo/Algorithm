#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
const int EMPTY = 0;
const int WALL = 1;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int HORSE[8][2] = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                         {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int K, W, H;
vector<vector<int>> board;

struct Pos {
    int x, y, k;
};

bool isIn(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

int bfs() {
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(K + 1, INF)));
    
    queue<Pos> q;
    q.push({0, 0, K});
    dist[0][0][K] = 0;

    while (!q.empty()) {
        auto [x, y, k] = q.front();
        q.pop();

        int curDist = dist[y][x][k];
        if (x == W - 1 && y == H - 1) return curDist;

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(x_, y_) && board[y_][x_] == EMPTY && dist[y_][x_][k] > curDist + 1) {
                dist[y_][x_][k] = curDist + 1;
                q.push({x_, y_, k});
            }
        }

        if (k == 0) continue;
        for (int dir = 0; dir < 8; dir++) {
            int y_ = y + HORSE[dir][0];
            int x_ = x + HORSE[dir][1];
            if (isIn(x_, y_) && board[y_][x_] == EMPTY && dist[y_][x_][k - 1] > curDist + 1) {
                dist[y_][x_][k - 1] = curDist + 1;
                q.push({x_, y_, k - 1});
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
        for (int x = 0; x < W; x++) cin >> board[y][x];

    cout << bfs() << "\n";

    return 0;
}