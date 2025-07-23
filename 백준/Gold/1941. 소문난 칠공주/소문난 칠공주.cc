#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int N = 5;
const int M = 5;
const int OFFSET[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<string> board(N);

bool isVaild(vector<int>& candi) {
    vector<bool> visited(7, false);
    queue<int> q;
    q.push(0); 
    visited[0] = true;

    int Y = 0, cnt = 0;
    while (!q.empty() && ++cnt) {
        int now = q.front(); 
        q.pop();

        int y = candi[now] / N;
        int x = candi[now] % M;

        if (board[y][x] == 'Y') Y++;

        for (int dir = 0; dir < 4; dir++) {
            int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            for (int i = 0; i < 7; i++) {
                if (!visited[i] && y_ == candi[i] / N && x_ == candi[i] % M) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    return cnt == 7 && Y < 4;
}

int comb(vector<int>& candi, int k) {
    if (candi.size() == 7) {
        if (isVaild(candi)) return 1;
        return 0;
    }

    int cnt = 0;
    for (int index = k; index < N * M; index++) {
        candi.push_back(index);
        cnt += comb(candi, index + 1);
        candi.pop_back();
    }
    return cnt;
}

int main() {
    for (int y = 0; y < N; y++) {
        cin >> board[y];
    }

    vector<int> candi;
    cout << comb(candi, 0) << '\n';

    return 0;
}