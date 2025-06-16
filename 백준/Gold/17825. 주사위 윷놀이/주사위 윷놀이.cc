#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int PLAYER_NUM = 4;
const int DICE_NUM = 10;
const int END_NODE = 21;

int answer = 0;
vector<int> dice, playerPos(PLAYER_NUM, 0);
vector<vector<int>> graph = {
    // 33개 노드 그래프화
    {1},      {2},  {3},  {4},  {5},   // 0 ~ 4
    {6, 22},  {7},  {8},  {9},  {10},  // 5 ~ 9
    {11, 29}, {12}, {13}, {14}, {15},  // 10 ~ 14
    {16, 26}, {17}, {18}, {19}, {20},  // 15 ~ 19
    {21},     {21}, {23}, {24}, {25},  // 20 ~ 24
    {31},     {27}, {28}, {25}, {30},  // 25 ~ 29
    {25},     {32}, {20}               // 30 ~ 32
};
vector<int> score = {
    // 33개 노드 점수
    0,  2,  4,  6,  8,   // 0 ~ 4
    10, 12, 14, 16, 18,  // 5 ~ 9
    20, 22, 24, 26, 28,  // 10 ~ 14
    30, 32, 34, 36, 38,  // 15 ~ 19
    40, 0,  13, 16, 19,  // 20 ~ 24
    25, 28, 27, 26, 22,  // 25 ~ 29
    24, 30, 35           // 30 ~ 32
};

// 어떤 말이 움직일 것인가에 대한 조합 생성
void backtracking(int sum, int index) {
    if (index == DICE_NUM) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < PLAYER_NUM; i++) {
        if (playerPos[i] == END_NODE) continue;
        
        // 이동 경로 따라가기
        int cur = playerPos[i];
        int next = cur;
        for (int m = 0; m < dice[index]; m++) {
            if (next == END_NODE) break;
            if (graph[next].size() == 2 && m == 0) next = graph[next][1]; // 분기
            else next = graph[next][0];                                   // 직진
        }

        // 도착 노드가 다른 말들과 겹치는지 확인
        bool flag = false;
        for (int j = 0; j < PLAYER_NUM; j++) {
            if (j != i && playerPos[j] == next && next != END_NODE) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        // 백트래킹
        playerPos[i] = next;
        backtracking(sum + score[next], index + 1);
        playerPos[i] = cur;
    }
}

int main() {
    dice = vector<int>(DICE_NUM);
    for (int i = 0; i < DICE_NUM; i++) {
        cin >> dice[i];
    }

    backtracking(0, 0);
    cout << answer;

    return 0;
}