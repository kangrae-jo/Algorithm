#include <vector>
#include <algorithm>

using namespace std;

const int EMPTY = 0;
const int PATH  = 1;
const int OFFSET[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int N, M;

bool isIn(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

// {이길 수 있는지, 이동 횟수}
pair<bool, int> dfs(vector<vector<int>>& board, int aY, int aX, int bY, int bX) {
    if (board[aY][aX] == EMPTY) {
        return {false, 0}; // 내 차례인데 발판이 없으면 패배
    }
    
    bool win = false;
    int minTurn = 1e9, maxTurn = 0;

    for (int dir = 0; dir < 4; dir++) {
        int aY_ = aY + OFFSET[dir][0];
        int aX_ = aX + OFFSET[dir][1];
        if (isIn(aY_, aX_) && board[aY_][aX_] == PATH) {
            board[aY][aX] = EMPTY;
            auto [oppWin, turns] = dfs(board, bY, bX, aY_, aX_);
            board[aY][aX] = PATH;

            if (!oppWin) {      
                // 상대가 못이기면, 내가 이기는 경우
                win = true;
                minTurn = min(minTurn, turns + 1);
            } else if (!win) {  
                // 이미 이길 수 있는 방법이 있으면 아래는 안 봐도 됨
                maxTurn = max(maxTurn, turns + 1);
            }
        }
    }
    // 이길 수 있으면 최소 턴, 아니면 최대 턴
    return win ? make_pair(true, minTurn) : make_pair(false, maxTurn);
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size();
    M = board[0].size();
    
    return dfs(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}