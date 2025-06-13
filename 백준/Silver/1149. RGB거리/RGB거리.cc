#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> rgb;
    for (int i = 0; i < N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        rgb.push_back({r, g, b});
    }

    vector<vector<int>> dp(N, vector<int> (3, 0));
    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];

    for (int i = 1; i < N; i ++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }

    cout << min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});

    return 0;
}