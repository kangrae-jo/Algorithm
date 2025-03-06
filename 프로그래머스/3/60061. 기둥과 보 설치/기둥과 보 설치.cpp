#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<vector<int>>& answer) {
    for (auto& frame : answer) {
        int x = frame[0], y = frame[1], a = frame[2];

        // 기둥 
        if (a == 0) {
            if (y == 0 || 
                find(answer.begin(), answer.end(), vector<int>{x, y-1, 0}) != answer.end() || 
                find(answer.begin(), answer.end(), vector<int>{x-1, y, 1}) != answer.end() || 
                find(answer.begin(), answer.end(), vector<int>{x, y, 1})   != answer.end()) continue;
            return false;
        }
        // 보
        else {
            if (find(answer.begin(), answer.end(), vector<int>{x, y-1, 0})  != answer.end() || 
                find(answer.begin(), answer.end(), vector<int>{x+1, y-1, 0})!= answer.end() || 
                find(answer.begin(), answer.end(), vector<int>{x-1, y, 1})  != answer.end() && 
                find(answer.begin(), answer.end(), vector<int>{x+1, y, 1})  != answer.end()) continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (auto& frame : build_frame) {
        int x = frame[0], y = frame[1], a = frame[2], b = frame[3];

        if (b == 0) {
            auto it = find(answer.begin(), answer.end(), vector<int>{x, y, a});
            if (it != answer.end()) {
                answer.erase(it); // 삭제 후 검사
                if (!possible(answer)) answer.push_back({x, y, a});
            }
        } 
        else {
            answer.push_back({x, y, a}); // 설치 후 검사
            if (!possible(answer)) answer.pop_back();
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}