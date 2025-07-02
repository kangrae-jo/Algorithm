#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int EMPTY = 0;
const int N = 9;

vector<vector<int>> board(N, vector<int>(N, EMPTY));

void checkRow(vector<bool>& cannot, int x) {
    for (int y = 0; y < N; y++) {
        cannot[board[y][x]] = true;
    }
}

void checkCol(vector<bool>& cannot, int y) {
    for (int x = 0; x < N; x++) {
        cannot[board[y][x]] = true;
    }
}

void checkSqr(vector<bool>& cannot, int y, int x) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cannot[board[(y / 3) * 3 + i][(x / 3) * 3 + j]] = true;
        }
    }
}

bool backtracking(int y_, int x_) {
    for (int y = y_; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == EMPTY) {
                vector<bool> cannot(N + 1, false);  // (y, x)에 놓을 수 없는 수들은 true
                checkRow(cannot, x);
                checkCol(cannot, y);
                checkSqr(cannot, y, x);

                for (int candi = 1; candi <= N; candi++) {
                    if (!cannot[candi]) {
                        board[y][x] = candi;
                        if (backtracking(y, x)) return true;
                        board[y][x] = EMPTY;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
        }
    }

    backtracking(0, 0);

    cout << endl;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << board[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}