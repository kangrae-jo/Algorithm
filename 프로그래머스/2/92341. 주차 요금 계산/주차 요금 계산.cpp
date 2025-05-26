#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXTIME = 23 * 60 + 59;

int toTime(string time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    return hh * 60 + mm;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    int baseTime = fees[0];
    int baseFee  = fees[1];
    int unitTime = fees[2];
    int unitFee  = fees[3];

    map<string, int> in;
    map<string, int> totalTime;

    for (string record : records) {
        string timeStr = record.substr(0, 5);
        string car     = record.substr(6, 4);
        string type    = record.substr(11);

        int time = toTime(timeStr);
        
        if (type == "IN") in[car] = time;
        else {
            totalTime[car] += time - in[car];
            in.erase(car);
        }
    }

    for (auto [car, time] : in) {
        totalTime[car] += MAXTIME - time;
    }

    vector<int> answer;
    for (auto [car, t] : totalTime) {
        int fee = baseFee;
        if (t > baseTime) {
            fee += ceil((t - baseTime) / (double)unitTime) * unitFee;
        }
        answer.push_back(fee);
    }

    return answer;
}