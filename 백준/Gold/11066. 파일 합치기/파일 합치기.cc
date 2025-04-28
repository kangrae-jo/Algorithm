#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> prefixSum;
vector<vector<int>> dp;

int getSum(int s, int e) {
    if (s == 0) return prefixSum[e];
    return prefixSum[e] - prefixSum[s - 1];
}

int solution(int s, int e) {
    if (dp[s][e] != -1) return dp[s][e];
    if (s == e) return 0; 

    dp[s][e] = 1e9;
    for (int m = s; m < e; m++) {
        dp[s][e] = min(dp[s][e], solution(s, m) + solution(m + 1, e) + getSum(s, e));
    }
    return dp[s][e];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;

        nums = vector<int>(K);
        prefixSum = vector<int>(K);
        dp = vector<vector<int>>(K, vector<int>(K, -1));

        for (int i = 0; i < K; i++) {
            cin >> nums[i];
            prefixSum[i] = nums[i];
            if (i > 0) prefixSum[i] += prefixSum[i - 1];
        }

        cout << solution(0, K - 1) << '\n';
    }

    return 0;
}