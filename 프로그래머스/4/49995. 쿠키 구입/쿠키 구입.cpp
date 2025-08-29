#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int N = cookie.size();
    
    int answer = 0;
    for (int m = 0; m < N - 1; m++) {
        int L = m, R = m + 1;
        int sumL = cookie[L], sumR = cookie[R];
        while (0 <= L && R < N) {
            if (sumL == sumR) {
                answer = max(answer, sumL);
                if (++R < N) sumR += cookie[R];
            } else if (sumL < sumR){
                if (0 <= --L) sumL += cookie[L];
            } else if (sumL > sumR) {
                if (++R < N) sumR += cookie[R];
            }
        }
    }
    
    return answer;
}