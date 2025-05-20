#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool isBan(string& a, string& b){
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue;
        if (b[i] != '*') return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<int> select(user_id.size(), 0);
    for (int i = 0; i < banned_id.size(); i++) {
        select[i] = 1;
    }
    
    int answer = 0;
    sort(select.begin(), select.end());
    sort(banned_id.begin(), banned_id.end());
    
    set<string> s;
    do {
        do{
            bool flag = true;
            int index= 0;
            vector<string> ans;
            for (int i = 0; i < select.size(); i++) {
                if (!select[i]) continue;
                if (!isBan(user_id[i], banned_id[index++])) {
                    flag = false;
                    break;
                }
                ans.push_back(user_id[i]);
            }
            if (flag) {
                string temp;
                for (string a : ans) temp +=a;
                s.insert(temp);
            }
        } while(next_permutation(banned_id.begin(), banned_id.end()));
    } while (next_permutation(select.begin(), select.end()));
    
    
    return s.size();
}