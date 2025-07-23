#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int N = 5;
const int M = 5;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int answer = 0;
vector<string> board(N);

bool isVaild(vector<int>& candi) {
    vector<bool> visited(7, false);
    queue<int> q;
    q.push(0); 
    visited[0] = true;

    int Y = 0, cnt = 1;
    if (board[candi[0] / N][candi[0] % M] == 'Y') Y++;

    while (!q.empty()) {
        int now = q.front(); q.pop();
        int y = candi[now] / N;
        int x = candi[now] % M;

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            for (int i = 0; i < 7; i++) {
                if (!visited[i] && y_ == candi[i] / N && x_ == candi[i] % M) {
                    visited[i] = true;
                    q.push(i);
                    cnt++;
                    if (board[y_][x_] == 'Y') Y++;
                }
            }
        }
    }
    return cnt == 7 && Y < 4;
}

void comb(vector<int>& candi, int k) {
    if (candi.size() == 7) {
        if (isVaild(candi)) answer++;
        return;
    }

    for (int index = k; index < N * M; index++) {
        candi.push_back(index);
        comb(candi, index + 1);
        candi.pop_back();
    }
}

int main() {
    for (int y = 0; y < N; y++) {
        cin >> board[y];
    }

    vector<int> candi;
    comb(candi, 0);

    cout << answer << '\n';

    return 0;
}