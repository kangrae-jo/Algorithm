#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>>& board, int N, int M, int Y, int X) {
    int sum1 = 0;
    for (int m = 1; m < M; m++) {
        if (Y - m >= 0) sum1 += board[Y - m][X];
        if (Y + m < N) sum1 += board[Y + m][X];
        if (X - m >= 0) sum1 += board[Y][X - m];
        if (X + m < N) sum1 += board[Y][X + m];
    }

    int sum2 = 0;
    for (int m = 1; m < M; m++) {
        if (Y - m >= 0 && X - m >= 0) sum2 += board[Y - m][X - m];
        if (Y + m < N && X - m >= 0) sum2 += board[Y + m][X - m];
        if (Y - m >= 0 && X + m < N) sum2 += board[Y - m][X + m];
        if (Y + m < N && X + m < N) sum2 += board[Y + m][X + m];
    }

    return max(sum1, sum2) + board[Y][X];
}

int main() {
    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> board(N, vector<int>(N, 0));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> board[y][x];
            }
        }

        int sum = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                int temp = solution(board, N, M, y, x);
                sum = max(sum, temp);
            }
        }

        cout << "#" << test << " " << sum << endl;
    }

    return 0;
}