#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> info;
    for (int i = 0; i < N; i++) {
        int from, to;
        cin >> from >> to;

        if (from > to) info.push_back({to, from});
    }

    sort(info.begin(), info.end());

    long long answer = 0;
    if (!info.empty()) {
        int L = info[0].first;   // 구간 시작
        int R = info[0].second;  // 구간 끝

        for (int i = 1; i < info.size(); i++) {
            auto [to, from] = info[i];
            if (to <= R) R = max(R, from);
            else {
                answer += (R - L);
                L = to;
                R = from;
            }
        }
        answer += (R - L);
    }

    cout << 2 * answer + M << '\n';

    return 0;
}