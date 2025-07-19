#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int N, M;

bool isIn(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

void solution(vector<vector<int>>& board, int sY, int sX) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push({sY, sX});
    visited[sY][sX] = true;

    int dist = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [y, x] = q.front();
            q.pop();

            board[y][x] = dist;

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + OFFSET[dir][0];
                int x_ = x + OFFSET[dir][1];
                if (isIn(y_, x_) && !visited[y_][x_] && board[y_][x_] == 1) {
                    q.push({y_, x_});
                    visited[y_][x_] = true;
                }
            }
        }
        dist--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    int sY = -1, sX = -1;
    vector<vector<int>> board(N, vector<int>(M));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> board[y][x];
            if (board[y][x] == 2) {
                sY = y;
                sX = x;
            }
        }
    }

    solution(board, sY, sX);

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == 1) cout << "-1 ";
            else cout << -board[y][x] << " ";
        }
        cout << "\n";
    }

    return 0;
}