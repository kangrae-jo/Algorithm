#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    vector<int> nums(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, false));
    for (int i = 1; i <= N; i++) {
        dp[i][i] = true;
    }
    for (int i = 1; i < N; i++) {
        if (nums[i] == nums[i + 1]) dp[i][i + 1] = true;
    }
    for (int s = N - 2; s >= 1; s--) {
        for (int e = s + 2; e <= N; e++) {
            if (nums[s] == nums[e] && dp[s + 1][e - 1]) dp[s][e] = true;
        }
    }

    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}