#include <vector>

using namespace std;

const int DIVID = 1000000007;
const int PUDDLE = -1;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> way(n, vector<int> (m, 0));
    for (auto puddle : puddles) way[puddle[1]-1][puddle[0]-1] = -1;
    
    way[0][0] = 1;    
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            if (way[y][x] == PUDDLE) continue;
            if (x != 0 && way[y][x-1] != PUDDLE) way[y][x] += way[y][x-1];
            if (y != 0 && way[y-1][x] != PUDDLE) way[y][x] += way[y-1][x];
            way[y][x] %= DIVID;
        }
    }
    
    return way[n-1][m-1];
}