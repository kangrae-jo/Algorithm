#include <vector>

using namespace std;

const int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> cityMap) {
    vector<vector<int>> down(m, vector<int>(n, 0));
    vector<vector<int>> right(m, vector<int>(n, 0));

    for (int y = 0; y < m; y++) {
        if (cityMap[y][0] == 1) break;
        down[y][0] = 1;
    }
    for (int x = 0; x < n; x++) {
        if (cityMap[0][x] == 1) break;
        right[0][x] = 1;
    }

    for (int y = 1; y < m; y++) {
        for (int x = 1; x < n; x++) {
            // 통행 금지
            if (cityMap[y][x] == 1) { 
                down[y][x] = right[y][x] = 0;
                continue;
            }

            // 위에서 내려오는 경우
            if (cityMap[y - 1][x] == 0) down[y][x] = (down[y - 1][x] + right[y - 1][x]) % MOD;
            else if (cityMap[y - 1][x] == 2) down[y][x] = down[y - 1][x];
            

            // 왼쪽에서 오는 경우
            if (cityMap[y][x - 1] == 0) right[y][x] = (down[y][x - 1] + right[y][x - 1]) % MOD;
            else if (cityMap[y][x - 1] == 2) right[y][x] = right[y][x - 1];
        }
    }

    return (down[m - 1][n - 1] + right[m - 1][n - 1]) % MOD;
}
