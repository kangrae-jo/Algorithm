#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int year, month, day;

// 파기해야하면 true
bool check(int yy, int mm, int dd) {
    if (year > yy) return true;                    
    else if (year == yy && month > mm) return true;
    else if (year == yy && month == mm && day >= dd) return true; 
    else return false; 
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    year = stoi(today.substr(0, 4));
    month = stoi(today.substr(5, 7));
    day = stoi(today.substr(8, 10));
    
    unordered_map<string, int> um; // 유형 -> 기간
    for (string t : terms) {
        string key = t.substr(0, 1);
        um[key] = stoi(t.substr(2));
    }
    
    vector<int> answer;
    for (int i = 0; i < privacies.size(); i++) {
        int yy = stoi(privacies[i].substr(0, 4));
        int mm = stoi(privacies[i].substr(5, 7));
        int dd = stoi(privacies[i].substr(8, 10));
        string type = privacies[i].substr(11);
        
        int mm_ = um[type];
        mm += mm_;
        
        while (mm > 12) {
            mm -= 12;
            yy += 1;
        }
        cout << yy << " " << mm << " " << dd << '\n';
        if (check(yy, mm, dd)) answer.push_back(i + 1);
    }
    
    return answer;
}