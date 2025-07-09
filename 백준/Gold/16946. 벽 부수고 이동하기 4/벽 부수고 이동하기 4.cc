#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int EMPTY = 0;
const int WALL = 1;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N, M;

bool isIn(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

void bfs(vector<vector<pair<int, int>>>& board, int y, int x, int id) {
    queue<pair<int, int>> q;
    q.push({y, x});
    board[y][x].first = id;

    queue<pair<int, int>> temp;

    int cnt = 0;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        cnt++;
        temp.push({y, x});

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(y_, x_) && board[y_][x_].first == 0 && board[y_][x_].second == EMPTY) {
                q.push({y_, x_});
                board[y_][x_].first = id;
            }
        }
    }

    while (!temp.empty()) {
        auto [y, x] = temp.front();
        temp.pop();

        board[y][x].second = cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<pair<int, int>>> bfsBoard(N, vector<pair<int, int>>(M));  // {id, WALL or cnt}
    for (int y = 0; y < N; y++) {
        string str;
        cin >> str;

        for (int x = 0; x < M; x++) {
            board[y][x] = str[x] - '0';
            bfsBoard[y][x] = {0, board[y][x]};
        }
    }

    for (int y = 0; y < N; y++) {
        string line;
        for (int x = 0; x < M; x++) {
            if (bfsBoard[y][x].second == EMPTY && bfsBoard[y][x].first == 0) {
                bfs(bfsBoard, y, x, y * M + x + 1);
            }
        }
    }

    vector<vector<int>> answer = board;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == WALL) {
                set<int> ids;
                for (int dir = 0; dir < 4; dir++) {
                    int y_ = y + OFFSET[dir][0];
                    int x_ = x + OFFSET[dir][1];
                    if (isIn(y_, x_) && board[y_][x_] != WALL) {
                        int id = bfsBoard[y_][x_].first;
                        if (ids.count(id) == 0) {
                            answer[y][x] += bfsBoard[y_][x_].second;
                            ids.insert(id);
                        }
                    }
                }
                answer[y][x] %= 10;
            }
            cout << answer[y][x];
        }
        cout << '\n';
    }

    return 0;
}