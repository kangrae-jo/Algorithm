#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> discounts;
vector<int> sale = {10, 20, 30, 40};
vector<int> answer = {0, 0};

void check(vector<vector<int>>& users, vector<int>& emoticons) {
    vector<int> candi = {0, 0};
    for (int i = 0; i < n; i++) {
        int rate  = users[i][0];
        int price = users[i][1];
        int userPrice = 0;
        
        for (int j = 0; j < m; j++) {
            if (rate <= discounts[j]) userPrice += ((emoticons[j] / 100) * (100 - discounts[j]));
        }
        if (userPrice >= price) candi[0]++;
        else candi[1] += userPrice;
    }
    
    if (answer[0] < candi[0] || (answer[0] == candi[0] && answer[1] < candi[1])) answer = candi;
}

void dfs(vector<vector<int>>& users, vector<int>& emoticons, int k) {
    if (k == m) {
        check(users, emoticons);
        return;
    }
    
    for (int s : sale) {
        discounts.push_back(s);
        dfs(users, emoticons, k + 1);
        discounts.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    n = users.size();
    m = emoticons.size();
    dfs(users, emoticons, 0);
    
    return answer;
}