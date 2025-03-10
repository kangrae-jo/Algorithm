#include <stack>
#include <iostream>

using namespace std;

bool solution(string s) {
    stack<char> oper;
    for (char c : s) {
        if (c == '(') oper.push(c);
        else {
            if (!oper.empty() && oper.top() == '(') oper.pop();
            else return false;
        }
    }
    
    if (oper.empty()) return true;
    else return false;
}