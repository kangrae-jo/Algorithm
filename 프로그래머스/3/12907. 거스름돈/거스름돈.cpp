#include <vector>
#include <algorithm>

using namespace std;

const long long DIV = 1000000007;

int solution(int n, vector<int> money) {
    sort(money.begin(), money.end());
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int m : money) {
        for (int i = m; i <= n; i++) {
            dp[i] = (dp[i] + dp[i - m]) % DIV;
        }
    }
    
    return dp[n] % DIV;
}