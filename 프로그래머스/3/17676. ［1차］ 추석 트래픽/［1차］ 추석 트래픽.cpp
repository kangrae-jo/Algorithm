#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const double OFFSET = 0.001;

struct Time {
    int hh, mm;
    double ss, process;
    
    double getEnd() const { return hh * 3600 + mm * 60 + ss; }
    double getStart() const { return getEnd() - process + OFFSET; }
};

int solution(vector<string> lines) {
    int N = lines.size();
    
    vector<Time> times;
    for (string line : lines) {
        Time temp;
        temp.hh = stoi(line.substr(11,2));
        temp.mm = stoi(line.substr(14,2));
        temp.ss = stod(line.substr(17,6));
        temp.process = stod(line.substr(23));
        
        times.push_back(temp);
    }
        
    int answer = 0;
    for (int i = 0; i < N; i++) {
        double start = times[i].getEnd(), end = start + 1;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (times[j].getStart() < end && times[j].getEnd() >= start) cnt++;
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}