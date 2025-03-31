#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#define EMPTY 0
#define HOME 1
#define CHICKEN 2

using namespace std;

int N, M, result = INT_MAX;
vector<pair<int, int>> chicken;
queue<pair<int, int>> home;

int getDistance(int x, int y, int x_, int y_) {
    return abs(x - x_) + abs(y - y_);
}

int calculateDistance(vector<pair<int, int>>& selected) {
    int sumDistance = 0;
    queue<pair<int, int>> q = home;

    while (!q.empty()) {
        int y_ = q.front().first;
        int x_ = q.front().second;
        q.pop();

        int minDistance = INT_MAX;
        for (auto& c : selected) {
            int distance = getDistance(x_, y_, c.second, c.first);
            minDistance = min(minDistance, distance);
        }
        sumDistance += minDistance;
    }

    return sumDistance;
}

void dfs(vector<pair<int, int>>& selected, int index, int count) {
    if (count == M) result = min(result, calculateDistance(selected));

    for (int i = index; i < chicken.size(); i++) {
        selected.push_back(chicken[i]);
        dfs(selected, i + 1, count + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int temp;
            cin >> temp;

            if (temp == HOME) home.push({y, x});
            if (temp == CHICKEN) chicken.push_back({y, x});
        }
    }

    vector<pair<int, int>> selected;
    dfs(selected, 0, 0);

    cout << result;

    return 0;
}