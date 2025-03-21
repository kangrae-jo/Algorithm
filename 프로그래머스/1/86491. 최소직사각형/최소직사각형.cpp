#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int longer = 0, shorter = 0;
    
    for (const auto& size : sizes) {   
        longer  = max(longer,  max(size[0], size[1]));
        shorter = max(shorter, min(size[0], size[1]));
    }

    return longer * shorter;
}