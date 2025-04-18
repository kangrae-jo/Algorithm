#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int MAX = 10;
const int OFFSET[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
vector<string> board;
bool visited[MAX][MAX][MAX][MAX];

struct Pos {
    int x, y;
};

pair<Pos, int> move(Pos p, int dir) {
    int cnt = 0;
    while (board[p.y + OFFSET[dir][0]][p.x + OFFSET[dir][1]] != '#' && board[p.y][p.x] != 'O') {
        p.y += OFFSET[dir][0];
        p.x += OFFSET[dir][1];
        cnt++;
    }
    return {p, cnt};
}

int bfs(Pos red, Pos blue) {
    queue<tuple<Pos, Pos, int>> q;
    q.push({red, blue, 0});
    visited[red.y][red.x][blue.y][blue.x] = true;

    while (!q.empty()) {
        auto [r, b, depth] = q.front();
        q.pop();

        if (depth >= 10) return -1;

        for (int dir = 0; dir < 4; dir++) {
            auto [r_, rCnt] = move(r, dir);
            auto [b_, bCnt] = move(b, dir);

            if (board[b_.y][b_.x] == 'O') continue;
            if (board[r_.y][r_.x] == 'O') return depth + 1;

            // When the balls overlap, 
            // move the one that moved farther one step back
            if (r_.x == b_.x && r_.y == b_.y) {
                if (rCnt > bCnt) {
                    r_.x -= OFFSET[dir][1];
                    r_.y -= OFFSET[dir][0];
                } else {
                    b_.x -= OFFSET[dir][1];
                    b_.y -= OFFSET[dir][0];
                }
            }

            if (!visited[r_.y][r_.x][b_.y][b_.x]) {
                visited[r_.y][r_.x][b_.y][b_.x] = true;
                q.push({r_, b_, depth + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    board.resize(N);

    Pos red, blue;
    for (int y = 0; y < N; y++) {
        cin >> board[y];
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 'R') red = {x, y};
            if (board[y][x] == 'B') blue = {x, y};
        }
    }

    cout << bfs(red, blue) << "\n";

    return 0;
}