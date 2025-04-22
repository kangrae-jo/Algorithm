#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void move(stack<int>& s, int cap) {
    int sum = 0, temp = 0;
    while (!s.empty()) {
        temp = s.top();
        if (sum + temp > cap) {
            s.pop();
            s.push(temp - (cap - sum));
            break;
        }
        sum += temp;
        s.pop();
    }
}

long long solution(int cap, int n, vector<int> deliveries_, vector<int> pickups_) {  
    stack<int> deliveries, pickups;
    for (int d : deliveries_) deliveries.push(d);
    for (int p : pickups_) pickups.push(p);
    
    long long answer = 0;
    while (!deliveries.empty() || !pickups.empty()) {
        while (!deliveries.empty() && deliveries.top() == 0) deliveries.pop();
        while (!pickups.empty() && pickups.top() == 0) pickups.pop();
        int size = max(deliveries.size(), pickups.size());
        
        move(deliveries, cap);
        move(pickups, cap);
        
        answer += size * 2;
    }
    
    return answer;
}