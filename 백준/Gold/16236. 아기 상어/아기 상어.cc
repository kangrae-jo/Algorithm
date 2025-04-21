#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

const int EMPTY = 0;
const int SHARK = 9;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N, M;
vector<vector<int>> space;
vector<queue<pair<int, int>>> vq(7);
pair<int, int> shark;

bool isAllEat(int sharkSize) {
    for (int i = 1; i < sharkSize; i++) 
        if (!vq[i].empty()) return true;
    return false;
}

bool isIn(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

int eat(int& sharkSize, int& sharkSizeCount) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    q.push(shark);
    dist[shark.first][shark.second] = 0;

    vector<tuple<int, int, int>> candidates; // 거리, y, x

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];

            if (!isIn(x_, y_) || dist[y_][x_] != -1 || space[y_][x_] > sharkSize) continue;
            
            dist[y_][x_] = dist[y][x] + 1;
            if (space[y_][x_] != EMPTY && space[y_][x_] < sharkSize) 
                candidates.push_back({dist[y_][x_], y_, x_});
            q.push({y_, x_});
        }
    }

    if (candidates.empty()) return -1;

    sort(candidates.begin(), candidates.end());
    auto [move, y, x] = candidates[0];

    space[shark.first][shark.second] = EMPTY;
    space[y][x] = SHARK;
    shark = {y, x};

    sharkSizeCount++;
    if (sharkSizeCount == sharkSize) {
        sharkSize++;
        sharkSizeCount = 0;
    }

    return move;
}

int solution() {
    int cnt = 0, sharkSize = 2, sharkSizeCount = 0;

    while (true) {
        int move = eat(sharkSize, sharkSizeCount);
        if (move == -1) break;
        cnt += move;
    }

    return cnt;
}

int main() {
    cin >> N;
    space.resize(N, vector<int>(N));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int temp;
            cin >> temp;
            space[y][x] = temp;
            if (temp == SHARK) shark = {y, x};
            else if (temp != EMPTY) vq[temp].push({y, x});
        }
    }

    cout << solution() << endl;

    return 0;
}