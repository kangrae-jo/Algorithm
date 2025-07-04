#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NOT = 0;  // 아직 방문하지 않은 곳
const int ING = 1;  // 현재 방문 중인 곳
const int DONE = 2; // 이전에 이미 방문한 곳

int N, M;
vector<int> graph;
vector<int> state;

bool dfs(int cur) {
    if (state[cur] == ING) return true;     // 현재 경로에서 다시 등장 -> 사이클
    if (state[cur] == DONE) return false;   // 이미 탐색 완료
    state[cur] = ING;
    
    bool ret = dfs(graph[cur]);
    state[cur] = DONE;
    return ret;
}

int main() {
    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; i++) cin >> board[i];

    graph = vector<int>(N * M);
    state = vector<int>(N * M, 0);

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int idx = y * M + x;
            if (board[y][x] == 'D') graph[idx] = (y + 1) * M + x;
            if (board[y][x] == 'U') graph[idx] = (y - 1) * M + x;
            if (board[y][x] == 'L') graph[idx] = y * M + (x - 1);
            if (board[y][x] == 'R') graph[idx] = y * M + (x + 1);
        }
    }

    int answer = 0;
    for (int i = 0; i < N * M; i++) {
        if (state[i] == 0 && dfs(i)) answer++;
    }

    cout << answer;

    return 0;
}