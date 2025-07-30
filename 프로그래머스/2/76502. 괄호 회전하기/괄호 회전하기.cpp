#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check(string str, int offset, int len) {
    stack<char> s;
    for (int i = 0; i < len; i++) {
        char c = str[(i + offset) % len];     
        if (c == '[' || c == '{' || c == '(') s.push(c);
        else {
            if (s.empty()) return false;
            if (c == ']' && s.top() != '[') return false;
            else if (c == '}' && s.top() != '{') return false;
            else if (c == ')' && s.top() != '(') return false;
            s.pop();
        }
    }
    return s.empty();
}

int solution(string str) {
    int len = str.size();
    int answer = 0;
    
    for (int i = 0; i < len; i++) {
        if (check(str, i, len)) answer++;
    }
    
    return answer;
}