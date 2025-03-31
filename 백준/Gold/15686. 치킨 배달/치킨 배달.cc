#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int EMPTY = 0;
const int HOUSE = 1;
const int CHICKEN = 2;

int N, M, result = INT_MAX;
vector<pair<int, int>> chicken;
queue<pair<int, int>> house;

int getDistance(int x, int y, int x_, int y_) {
    return abs(x - x_) + abs(y - y_);
}

int calculateDistance(vector<pair<int, int>>& selected) {
    int sumDistance = 0;
    
    queue<pair<int, int>> q = house;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        int minDistance = INT_MAX;
        for (auto [y_, x_] : selected) minDistance = min(minDistance, getDistance(x, y, x_, y_));
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

    int temp;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (cin >> temp && temp == HOUSE) house.push({y, x});
            if (temp == CHICKEN) chicken.push_back({y, x});
        }
    }

    vector<pair<int, int>> selected;
    dfs(selected, 0, 0);

    cout << result;

    return 0;
}
