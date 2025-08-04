#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool compareTo(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), compareTo);

    int answer = 0;
    int curE = -1;
    for (int i = 0; i < targets.size(); i++) {
        //cout << curE << endl;
        int s = targets[i][0];
        int e = targets[i][1];
        
        if (s >= curE) {
            answer++;
            curE = e;
        }
    }
    
    return answer;
}