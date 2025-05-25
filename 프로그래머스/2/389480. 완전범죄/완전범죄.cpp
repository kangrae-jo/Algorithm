#include <vector>

using namespace std;

const int MAX = 121; 
bool dp[MAX][MAX];

int solution(vector<vector<int>> info, int n, int m) {
    dp[0][0] = true; 

    for (int i = 0; i < info.size(); i++) {
        bool nextDp[MAX][MAX] = { false, };
        int A = info[i][0];
        int B = info[i][1];

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (!dp[a][b]) continue;
                if (a + A < n) nextDp[a + A][b] = true;
                if (b + B < m) nextDp[a][b + B] = true;
            }
        }

        for (int a = 0; a < n; a++) 
            for (int b = 0; b < m; b++) 
                dp[a][b] = nextDp[a][b];
    }
    

    for (int a = 0; a < n; a++) 
        for (int b = 0; b < m; b++) 
            if (dp[a][b]) return a;
    
    return -1; 
}