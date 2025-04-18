#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N;
vector<string> image;

struct Pos {
    int x, y;
};

bool isIn(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

void makeArea(vector<vector<bool>>& visited, Pos start, char color) {
    queue<Pos> q;
    q.push(start);
    visited[start.y][start.x] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(x_, y_) && image[y_][x_] == color && !visited[y_][x_]) {
                visited[y_][x_] = true;
                q.push({x_, y_});
            }
        }
    }
}

int getArea() {
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    int cnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                makeArea(visited, {x, y}, image[y][x]);
                cnt++;
            }
            if (image[y][x] == 'G') image[y][x] = 'R';
        }
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    image.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> image[i];
    }

    cout << getArea() << " " << getArea() << endl;

    return 0;
}