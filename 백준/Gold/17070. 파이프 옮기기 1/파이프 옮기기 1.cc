#include <iostream>
#include <vector>

using namespace std;

int N;
int board[17][17];
int dp[17][17][3]; // [y][x][dir]: dir 0: 가로, 1: 세로, 2: 대각

int main() {
    cin >> N;
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= N; x++)
            cin >> board[y][x];

    dp[1][2][0] = 1; // 시작 상태: (1,1)-(1,2) 가로 방향

    for (int y = 1; y <= N; y++) {
        for (int x = 2; x <= N; x++) {
            if (board[y][x] == 1) continue;

            // 가로
            dp[y][x][0] += dp[y][x - 1][0] + dp[y][x - 1][2];
            // 세로
            dp[y][x][1] += dp[y - 1][x][1] + dp[y - 1][x][2];
            // 대각선
            if (board[y - 1][x] == 0 && board[y][x - 1] == 0)
                dp[y][x][2] += dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
        }
    }

    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << '\n';
    
    return 0;
}