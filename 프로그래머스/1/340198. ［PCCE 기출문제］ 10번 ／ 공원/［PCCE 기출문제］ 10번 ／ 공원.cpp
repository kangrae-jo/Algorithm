#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string EMPTY = "-1";
int N, M;

bool check(vector<vector<string>>& park, int mat, int x, int y) {
    for (int i = 0; i < mat; i++) 
        for (int j = 0; j < mat; j++) 
            if (park[y + i][x + j] != EMPTY) return false;
    return true;
}

bool canPut(vector<vector<string>>& park, int mat) {
    for (int y = 0; y <= N - mat; y++) 
        for (int x = 0; x <= M - mat; x++) 
            if (check(park, mat, x, y)) return true;
    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    N = park.size();
    M = park[0].size();
    sort(mats.rbegin(), mats.rend());
    
    for (int mat : mats) 
        if (canPut(park, mat)) return mat;
    return -1;
}