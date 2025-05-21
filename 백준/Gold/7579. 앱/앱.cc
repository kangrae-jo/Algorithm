#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), cost(N);
    int costSum = 0;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        costSum += cost[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(costSum + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= costSum; j++) {
            if (j - cost[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i - 1]] + A[i - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int j = 0; j <= costSum; j++) {
        if (dp[N][j] >= M) {
            cout << j << endl;
            break;
        }
    }

    return 0;
}