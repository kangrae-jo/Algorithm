#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    vector<vector<int>> board((n + w - 1) / w, vector<int>(w + 1, 0));
    
    for (int h = 0; h < board.size(); h++) {
        for (int i = 1 ; i <= w; i++) {
            board[h][i] = i + w * h;
            if (board[h][i] >= n) break;
        }   
        if (h % 2 != 0) reverse(board[h].begin() + 1, board[h].end());
    }
    
    int answer = 0;
    for (int h = 0; h < board.size(); h++) {
        for (int i = 1 ; i <= w; i++) {
            if (board[h][i] == num) {
                while (h < board.size() && board[h][i] != 0) {
                    cout << h << "\t" << i << endl;
                    answer++;
                    h++;
                }
                return answer;
            }
        }
    }
    
    return answer;
}