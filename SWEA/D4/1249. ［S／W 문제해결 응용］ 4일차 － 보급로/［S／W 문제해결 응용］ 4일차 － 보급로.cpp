#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
    
const int OFFSET[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};

bool isIn(int y, int x, int N) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int solution(vector<string>& board, int N) {
	vector<vector<bool>> visited(N, vector<bool>(N,false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0,0}}); // cost {y, x}
    visited[0][0] = true;
    
    while(!pq.empty()) {
		pair<int, pair<int, int>> cur = pq.top();
        pq.pop();
        
        int cost = cur.first;
        int y = cur.second.first;
        int x = cur.second.second;
        
        if (y == N -1 && x == N-1) return cost;
        
        for (int dir = 0; dir < 4; dir++) {
			int y_ = y + OFFSET[dir][0];
            int x_ = x + OFFSET[dir][1];
            if (isIn(y_,x_, N) && !visited[y_][x_]) {
                pq.push({cost + (board[y_][x_] - '0'), {y_, x_}});
                visited[y_][x_] = true;
            }
        }
        
    }
    
    return -1;
}

int main(int argc, char** argv) {
	int T;
	cin>>T;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
        cin >> N;
        
        vector<string> board(N);
        for (int i = 0; i < N; i++) {
        	cin >> board[i];
        }
        
        int answer  = solution(board, N);
		cout << "#" << test_case << " " << answer << '\n';
	}
    
	return 0;
}