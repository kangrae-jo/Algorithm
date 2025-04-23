#include <string>
#include <vector>

using namespace std;

bool can(int& a, int& b, int& c, int& d) {
    if (a >= c && b >= d || a >= d && b >= c) return true;
    
    if (c > d) c /= 2;
    else d /= 2;
    
    return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while (1) {
        if (can(wallet[0], wallet[1], bill[0], bill[1])) break;
        answer++;
    }
    return answer;
}