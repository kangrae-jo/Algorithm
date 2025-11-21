#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100;

int solve(int sY, int sX, const vector<vector<int>>& board) {
    int y = sY;
    int x = sX;

    while (y > 0) {
        // 왼쪽으로 이동
        if (x - 1 >= 0 && board[y][x - 1] == 1) {
            while (x - 1 >= 0 && board[y][x - 1] == 1) {
                x--;
            }
            y--;
        }
        // 오른쪽으로 이동
        else if (x + 1 < SIZE && board[y][x + 1] == 1) {
            while (x + 1 < SIZE && board[y][x + 1] == 1) {
                x++;
            }
            y--;
        }
        // 위로 이동
        else {
            y--;
        }
    }

    return x;
}

int main() {
    int T;
   	while (cin >> T) {
        vector<vector<int>> board(SIZE, vector<int>(SIZE));
        int startY, startX;

        for (int y = 0; y < SIZE; y++) {
            for (int x = 0; x < SIZE; x++) {
                cin >> board[y][x];
                if (board[y][x] == 2) {
                    startY = y;
                    startX = x;
                }
            }
        }

        int answer = solve(startY, startX, board);
        cout << "#" << T << " " << answer << "\n";
    }
    return 0;
}
