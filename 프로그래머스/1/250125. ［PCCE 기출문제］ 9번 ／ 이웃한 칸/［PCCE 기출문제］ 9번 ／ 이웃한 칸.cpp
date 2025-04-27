#include <string>
#include <vector>

using namespace std;

const int OFFSET[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool isIn(int n, int h, int w) {
    return 0 <= h && h < n && 0 <= w && w < n;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    for(int dir = 0; dir < 4; dir++) {
        int h_ = h + OFFSET[dir][0];
        int w_ = w + OFFSET[dir][1];
        if (isIn(board.size(), h_, w_) && board[h][w] == board[h_][w_]) answer++;
    }
    return answer;
}