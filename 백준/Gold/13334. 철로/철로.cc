#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool compareTo(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n;
    vector<pair<int, int>> ho(n);
    for (int i = 0; i < n; i++) {
        int h, o;
        cin >> h >> o;
        if (h < o) ho[i] = {h, o};
        else ho[i] = {o, h};
    }
    cin >> d;

    sort(ho.begin(), ho.end(), compareTo);

    priority_queue<int, vector<int>, greater<>> pq;
    int answer = 0;

    for (auto [s, e] : ho) {
        if (e - s <= d) pq.push(s);
        else continue;

        while (!pq.empty()) {
            if (pq.top() < e - d) pq.pop();
            else {
                answer = max(answer, (int)pq.size());
                break;
            }
        }
    }

    cout << answer;

    return 0;
}