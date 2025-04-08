#include <iostream>
#include <vector>

using namespace std;

const int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int answer = 0;

bool isIn(int x, int y, int N) { 
    return 0 <= y && y < N && 0 <= x && x < N; 
}

void spread(vector<vector<int>>& sand, int xX, int xY, int dir, int N) {
    int yY = xY + offset[dir][0];
    int yX = xX + offset[dir][1];

    // 모래 양
    int pY = sand[yY][yX];
    int p1 = pY * 1 / 100;
    int p2 = pY * 2 / 100;
    int p5 = pY * 5 / 100;
    int p7 = pY * 7 / 100;
    int p10 = pY * 10 / 100;
    int pAlpha = pY - (2 * p1) - (2 * p2) - p5 - (2 * p7) - (2 * p10);

    // 진행 방향 오른쪽 부분
    int yY_ = yY + 2 * offset[(dir + 1) % 4][0];
    int yX_ = yX + 2 * offset[(dir + 1) % 4][1];
    if (!isIn(yX_, yY_, N)) answer += p2;
    else sand[yY_][yX_] += p2;

    yY_ = yY + offset[(dir + 1) % 4][0];
    yX_ = yX + offset[(dir + 1) % 4][1];
    if (!isIn(yX_, yY_, N)) answer += p7;
    else sand[yY_][yX_] += p7;

    yY_ += offset[(dir + 2) % 4][0];
    yX_ += offset[(dir + 2) % 4][1];
    if (!isIn(yX_, yY_, N)) answer += p1;
    else sand[yY_][yX_] += p1;

    yY_ += 2 * offset[dir][0];
    yX_ += 2 * offset[dir][1];
    if (!isIn(yX_, yY_, N)) answer += p10;
    else sand[yY_][yX_] += p10;

    // 진행 방향 왼쪽 부분
    yY_ = yY + 2 * offset[(dir + 3) % 4][0];
    yX_ = yX + 2 * offset[(dir + 3) % 4][1];
    if (!isIn(yX_, yY_, N)) answer += p2;
    else sand[yY_][yX_] += p2;

    yY_ = yY + offset[(dir + 3) % 4][0];
    yX_ = yX + offset[(dir + 3) % 4][1];
    if (!isIn(yX_, yY_, N)) answer += p7;
    else sand[yY_][yX_] += p7;

    yY_ += offset[(dir + 2) % 4][0];
    yX_ += offset[(dir + 2) % 4][1];
    if (!isIn(yX_, yY_, N)) answer += p1;
    else sand[yY_][yX_] += p1;

    yY_ += 2 * offset[dir][0];
    yX_ += 2 * offset[dir][1];
    if (!isIn(yX_, yY_, N)) answer += p10;
    else sand[yY_][yX_] += p10;

    // 진행 방향 앞 부분
    yY_ = yY + offset[dir][0];
    yX_ = yX + offset[dir][1];
    if (!isIn(yX_, yY_, N)) answer += pAlpha;
    else sand[yY_][yX_] += pAlpha;

    yY_ = yY + 2 * offset[dir][0];
    yX_ = yX + 2 * offset[dir][1];
    if (!isIn(yX_, yY_, N)) answer += p5;
    else sand[yY_][yX_] += p5;

    // 바람이 분 곳 y는 모래가 0
    sand[yY][yX] = 0;
}

void tornado(vector<vector<int>>& sand, int N) {
    int x = N / 2, y = N / 2;
    int dir = 3;

    for (int len = 1; len < N; len++) {
        int move = 2;
        if (len == N - 1) move++;

        for (int t = 0; t < move; t++) {
            for (int i = 0; i < len; i++) {
                spread(sand, x, y, dir, N);
                y += offset[dir][0];
                x += offset[dir][1];
            }
            dir = (dir + 1) % 4;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> sand(N, vector<int>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> sand[y][x];
        }
    }

    tornado(sand, N);
    cout << answer << endl;

    return 0;
}