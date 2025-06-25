#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int EMPTY = 0;
const int TIMES = 5;

int answer = 0;

vector<int> mergeLine(vector<int> line) {
    vector<int> result;
    int prev = 0;
    for (int num : line) {
        if (num == 0) continue;
        if (prev == 0)
            prev = num;
        else if (prev == num) {
            result.push_back(prev * 2);
            prev = 0;
        } else {
            result.push_back(prev);
            prev = num;
        }
    }
    if (prev) result.push_back(prev);
    while (result.size() < line.size()) result.push_back(0);
    return result;
}

int check(vector<vector<int>> board, int N, vector<int> cmd) {
    for (int dir : cmd) {
        if (dir == 0) {  // down
            for (int x = 0; x < N; x++) {
                vector<int> line;
                for (int y = N - 1; y >= 0; y--) line.push_back(board[y][x]);
                line = mergeLine(line);
                for (int y = N - 1, idx = 0; y >= 0; y--, idx++)
                    board[y][x] = line[idx];
            }
        }
        if (dir == 1) {  // right
            for (int y = 0; y < N; y++) {
                vector<int> line;
                for (int x = N - 1; x >= 0; x--) line.push_back(board[y][x]);
                line = mergeLine(line);
                for (int x = N - 1, idx = 0; x >= 0; x--, idx++)
                    board[y][x] = line[idx];
            }
        }
        if (dir == 2) {  // up
            for (int x = 0; x < N; x++) {
                vector<int> line;
                for (int y = 0; y < N; y++) line.push_back(board[y][x]);
                line = mergeLine(line);
                for (int y = 0, idx = 0; y < N; y++, idx++)
                    board[y][x] = line[idx];
            }
        }
        if (dir == 3) {  // left
            for (int y = 0; y < N; y++) {
                vector<int> line;
                for (int x = 0; x < N; x++) line.push_back(board[y][x]);
                line = mergeLine(line);
                for (int x = 0, idx = 0; x < N; x++, idx++)
                    board[y][x] = line[idx];
            }
        }
    }

    int maxV = -1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            maxV = max(maxV, board[y][x]);
        }
    }
    return maxV;
}

void dfs(vector<vector<int>>& board, int N, vector<int> cmd) {
    if (cmd.size() == TIMES) {
        answer = max(answer, check(board, N, cmd));
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        cmd.push_back(dir);
        dfs(board, N, cmd);
        cmd.pop_back();
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
        }
    }

    dfs(board, N, {});

    cout << answer;

    return 0;
}