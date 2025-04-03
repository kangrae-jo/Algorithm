#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

const char WALL = '0';
const char PATH = '1';
const char VISITED = '2';

const int offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isMoveable(vector<string>& maze, int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M && maze[y][x] == PATH;
}

int bfs(vector<string>& maze) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    maze[0][0] = VISITED;

    int cnt = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [y, x] = q.front();
            q.pop();

            if (y == N - 1 && x == M - 1) return cnt;

            for (int dir = 0; dir < 4; dir++) {
                int y_ = y + offset[dir][0];
                int x_ = x + offset[dir][1];
                if (isMoveable(maze, y_, x_)) {
                    maze[y_][x_] = VISITED;
                    q.push({y_, x_});
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    cin >> N >> M;

    vector<string> maze(N);
    for (int y = 0; y < N; y++) cin >> maze[y];

    cout << bfs(maze) << endl;

    return 0;
}