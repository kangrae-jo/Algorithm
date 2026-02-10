#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        int T, P;
        cin >> T >> P;
        arr[i] = {T, P};
    }

    vector<int> dp(N + 2, 0);
    for (int day = 1; day <= N; day++) {
        // 상담 x
        dp[day + 1] = max(dp[day + 1], dp[day]);

        // 상담 o
        int end = day + arr[day].first;
        if (end <= N + 1) dp[end] = max(dp[end], dp[day] + arr[day].second);
    }

    cout << dp[N + 1] << '\n';

    return 0;
}
