#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>> m;
vector<string> answer;
int k;

bool dfs(string airport, vector<string>& path) {
    path.push_back(airport);
    if (path.size() == k + 1) {
        answer = path;
        return true;
    }

    for (string& next : m[airport]) {
        if (!next.empty()) {  
            string temp = next;
            next = ""; 
            if (dfs(temp, path)) return true;
            next = temp;
        }
    }
    path.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());

    k = tickets.size();
    for (auto& ticket : tickets) {
        m[ticket[0]].push_back(ticket[1]);
    }

    vector<string> path;
    dfs("ICN", path);

    return answer;
}