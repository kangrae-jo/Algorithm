#include <string>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    
    for (int i = 0; i < len; i++) {
        int move = name[i] - 'A';
        answer += min(move, 26 - move);
    }
    
    int minMove = len - 1; 
    for (int i = 0; i < len; i++) {
        int next = i + 1;
        while (next < len && name[next] == 'A') next++;
        
        int leftRightMove = i + (len - next) + min(i, len - next);
        minMove = min(minMove, leftRightMove);
    }
    
    return answer + minMove;
}