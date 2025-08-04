#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void move(stack<int>& s, int capacity) {
    int carry = 0;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        
        // 현재 적재 가능한 만큼만 들고가기
        if (carry + cur > capacity) {
            s.push(cur - (capacity - carry));
            break;
        }
        // 다 들고 가기
        carry += cur;
    }
}

long long solution(int cap, int n, vector<int> deliveries_, vector<int> pickups_) { 
    // 스택으로 표현
    stack<int> deliveries, pickups;
    for (int d : deliveries_) deliveries.push(d);
    for (int p : pickups_)    pickups.push(p);
    
    // 배달과 수거
    long long answer = 0;
    while (!deliveries.empty() || !pickups.empty()) {
        while (!deliveries.empty() && deliveries.top() == 0) deliveries.pop();
        while (!pickups.empty()    && pickups.top() == 0)    pickups.pop();
        int size = max(deliveries.size(), pickups.size());
        
        move(deliveries, cap);
        move(pickups, cap);
        
        answer += size * 2;
    }
    
    return answer;
}