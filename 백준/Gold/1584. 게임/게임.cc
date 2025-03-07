#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pos {
    int x, y;
};

const int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int SIZE = 501;
const int SAFE = 0;
const int DANGER = 1;
const int KILL = 2;

vector<vector<int>> area(SIZE, vector<int>(SIZE, SAFE));
vector<vector<int>> dist(SIZE, vector<int>(SIZE, 1e9));

void init(const int& ZONE) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int sX = min(x1, x2);
    int sY = min(y1, y2);
    int eX = max(x1, x2);
    int eY = max(y1, y2);

    for (int y = sY; y <= eY; y++)
        for (int x = sX; x <= eX; x++) area[y][x] = ZONE;
}

bool isMoveable(int y, int x) {
    return 0 <= y && y < SIZE && 0 <= x && x < SIZE && area[y][x] != KILL;
}

int dikstra(int sY, int sX) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {sY, sX}});
    dist[sY][sX] = 0;
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int damage = cur.first;
        int y = cur.second.first;
        int x = cur.second.second;

        if (y == SIZE - 1 && x == SIZE - 1) return damage;
        if (dist[y][x] < damage) continue;

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + offset[dir][0];
            int x_ = x + offset[dir][1];
            if (isMoveable(y_, x_)) {
                int nextDamage = damage + area[y_][x_];
                if (nextDamage < dist[y_][x_]) {
                    dist[y_][x_] = nextDamage;
                    pq.push({damage + area[y_][x_], {y_, x_}});
                }
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N;
    while (N--) init(DANGER);
    cin >> M;
    while (M--) init(KILL);

    cout << dikstra(0, 0) << '\n';

    return 0;
}
