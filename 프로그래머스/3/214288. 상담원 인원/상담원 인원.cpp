#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> requests;
vector<vector<int>> mentors;  

int getWaitTime(int k, const vector<int>& mentor) {
    int waitTime = 0;
    
    for (int i = 1; i <= k; i++) {  
        vector<pair<int, int>> req = requests[i];
        sort(req.begin(), req.end());
        
        int agentCnt = mentor[i];
        priority_queue<int, vector<int>, greater<>> agentQ;
        for (int j = 0; j < agentCnt; j++) agentQ.push(0);

        for (auto [a, b] : req) {
            int earliestEnd = agentQ.top(); 
            agentQ.pop();
            
            if (earliestEnd > a) {
                waitTime += (earliestEnd - a); 
                earliestEnd += (b - a);
            } 
            else earliestEnd = b;
            agentQ.push(earliestEnd);
        }
    }
    return waitTime;
}

void backtracking(int remain, int idx, vector<int>& mentor) {
    if (remain == 0) {
        mentors.push_back(mentor);
        return;
    }
    for (int i = idx; i < mentor.size(); i++) {
        mentor[i]++;
        backtracking(remain - 1, i, mentor);
        mentor[i]--;
    }
}

int solve(int n, int k) {
    int minWaitTime = INT_MAX;
    for (const auto& mentor : mentors) 
        minWaitTime = min(minWaitTime, getWaitTime(k, mentor));
    return minWaitTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    requests.resize(k + 1);
    for (auto& req : reqs) {
        int a = req[0];
        int b = req[0] + req[1];
        int c = req[2];
        requests[c].push_back({a, b});
    }

    vector<int> mentor(k + 1, 1); 
    backtracking(n - k, 1, mentor);  

    return solve(n - k, k);
}