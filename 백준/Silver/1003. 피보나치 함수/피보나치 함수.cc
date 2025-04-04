#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    int N;
    vector<pair<int, int>> dp(41, {0, 0});
    dp[0] = {1, 0};
    dp[1] = {0, 1};

    for (int i = 2; i <= 40; i++) {
        dp[i].first  = dp[i - 1].first  + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    while (T-- && cin >> N) {
        auto [a, b] = dp[N];
        cout << a << " " << b << '\n';
    }

    return 0;
}