#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> kinds(gems.begin(), gems.end());
    int total = kinds.size();

    unordered_map<string, int> cnt; // 현재 윈도우 보석 개수
    int found = 0;                  // 현재 윈도우 안에 들어온 보석 종류 수
    int bestL = 0, bestR = gems.size() - 1;
    int bestLen = bestR - bestL;
    
    int l = 0, r = 0;
    while (true) {
        // 모든 종류를 아직 못 채웠다면 오른쪽 확장
        if (found < total) {
            if (r == gems.size()) break;
            if (cnt[gems[r]] == 0) found++;
            cnt[gems[r++]]++;
        }
        // 모든 종류를 포함했다면 왼쪽 줄여서 최소 길이 갱신
        else {
            int curLen = r - l - 1;
            if (curLen < bestLen) {
                bestLen = curLen;
                bestL = l;
                bestR = r - 1;
            }
            
            if (--cnt[gems[l]] == 0) found--; 
            l++;
        }
    }

    return {bestL + 1, bestR + 1};
}
