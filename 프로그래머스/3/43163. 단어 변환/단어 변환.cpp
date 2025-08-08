#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool canTransform(string a, string b) {
    bool flag = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            if (!flag) flag = true;
            else return false;
        }
    }
    return true;
}

int bfs(string start, string end, vector<string>& words) {
    unordered_map<string, bool> visited;
    queue<string> q;
    q.push(start);
    visited[start] = true;
    
    int cnt = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            string cur = q.front();
            q.pop();
        
            if (cur == end) return cnt;
        
            for (string word : words) {
                if (!visited[word] && canTransform(cur, word)) {
                    q.push(word);
                    visited[word] = true;
                }
            }
        }
        cnt++;
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    return bfs(begin, target, words);
}