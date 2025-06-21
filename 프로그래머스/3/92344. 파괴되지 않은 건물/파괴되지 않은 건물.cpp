#include <vector>

using namespace std;

const int ATTACK = 1;
const int HEAL   = 2;

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int N = board.size();
    int M = board[0].size();

    // 누적합 배열
    vector<vector<int>> sum(N + 2, vector<int>(M + 2, 0));

    // skills 적용
    for (auto& skill : skills) {
        int type = skill[0];
        int r1 = skill[1];
        int c1 = skill[2];
        int r2 = skill[3];
        int c2 = skill[4];
        int degree = skill[5];
        if (type == ATTACK) degree *= -1;

        sum[r1][c1] += degree;
        sum[r1][c2 + 1] -= degree;
        sum[r2 + 1][c1] -= degree;
        sum[r2 + 1][c2 + 1] += degree;
    }

    // 누적합 연산
    for (int y = 0; y < N + 1; y++) 
        for (int x = 1; x < M + 1; x++) 
            sum[y][x] += sum[y][x - 1];
        
    for (int x = 0; x < M + 1; x++) 
        for (int y = 1; y < N + 1; y++) 
            sum[y][x] += sum[y - 1][x];
    
    // 최종 카운트
    int answer = 0;
    for (int y = 0; y < N; y++) 
        for (int x = 0; x < M; x++) 
            if (board[y][x] + sum[y][x] > 0) answer++;
    
    return answer;
}