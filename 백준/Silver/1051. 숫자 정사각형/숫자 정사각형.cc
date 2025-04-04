#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSame(vector<string>& board, int x, int y, int i) {
    return (board[y + i][x] == board[y][x] &&
            board[y][x + i] == board[y][x] &&
            board[y + i][x + i] == board[y][x]);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int maxLen = min(N, M);
    for (int i = maxLen - 1; i >= 0; i--) { 
        for (int y = 0; y + i < N; y++) {
            for (int x = 0; x + i < M; x++) {
                if (isSame(board, x, y, i)) {
                    cout << (i + 1) * (i + 1) << '\n';
                    return 0;
                }
            }
        }
    }

    cout << 1 << '\n';  

    return 0;
}