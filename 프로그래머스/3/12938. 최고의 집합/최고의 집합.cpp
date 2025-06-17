#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, int S) {
    if (S < N) return {-1};
    
    int num = S / N;
    vector<int> answer(N, num);
    
    int over = S - num * N;
    int index = N - 1;
    
    while (over--) {
        answer[index--]++;
    }
    
    return answer;
}