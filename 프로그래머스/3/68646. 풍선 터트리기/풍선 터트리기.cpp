#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int N = a.size();
    if (N <= 3) return N; 

    vector<int> leftMin(N, a[0]), rightMin(N, a[N-1]);
    for (int i = 1; i < N; i++)    leftMin[i] = min(leftMin[i-1], a[i]);
    for (int i = N-2; i >= 0; i--) rightMin[i] = min(rightMin[i+1], a[i]);

    int answer = 2; // 양 끝 풍선 항상 가능
    for (int i = 1; i < N-1; i++) {
        if (a[i] <= leftMin[i-1] || a[i] <= rightMin[i+1]) answer++;
    }
    
    return answer;
}