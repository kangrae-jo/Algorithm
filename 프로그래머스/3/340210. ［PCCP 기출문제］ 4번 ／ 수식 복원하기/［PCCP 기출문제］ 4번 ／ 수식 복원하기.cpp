#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

int nToTen(const string& s, int base, bool& ok) {
    int val = 0;
    ok = true;
    for (char ch : s) {
        if (ch < '0' || ch > '9') { 
            ok = false; 
            return 0; 
        }
        
        int d = ch - '0';
        if (d >= base) { 
            ok = false; 
            return 0; 
        }
        val = val * base + d;
    }
    return val;
}

string tenToN(int val, int base) {
    if (val == 0) return "0";
    string result = "";
    while (val > 0) {
        result = char('0' + val % base) + result;
        val /= base;
    }
    return result;
}

struct Exp {
    string a, s, b, c;
    Exp(string a_, string s_, string b_, string c_) : a(a_), s(s_), b(b_), c(c_) {}
    
    bool isCollectAry(int ary) {
        bool okA, okB, okC;
        int A = nToTen(a, ary, okA);
        int B = nToTen(b, ary, okB);
        int C = nToTen(c, ary, okC);
        if (!okA || !okB || !okC) return false;
        if (s == "+") return (A + B) == C;
        else          return (A - B) == C;
    }
    
    string getResult(int ary) {
        bool okA, okB;
        int A = nToTen(a, ary, okA);
        int B = nToTen(b, ary, okB);
        if (!okA || !okB) return "";
        
        int result;
        if (s == "+") result = A + B;
        else          result = A - B;
        
        return tenToN(result, ary);
    }
    
    string toString(string result) {
        return a + " " + s + " " +  b + " = " + result;
    }
    
    // 식에 포함된 모든 숫자에서 가장 큰 자릿수 찾기
    int getMaxDigit() {
        int maxDigit = 0;
        for (char ch : a) {
            if (ch >= '0' && ch <= '9') maxDigit = max(maxDigit, ch - '0');
        }
        for (char ch : b) {
            if (ch >= '0' && ch <= '9') maxDigit = max(maxDigit, ch - '0');
        }
        if (c == "X") return maxDigit;
        for (char ch : c) {
            if (ch >= '0' && ch <= '9') maxDigit = max(maxDigit, ch - '0');
        }
        return maxDigit;
    }
};

vector<string> solution(vector<string> expressions) {
    vector<Exp> xs, exps;
    for (int i = 0; i < expressions.size(); i++) {
        stringstream ss(expressions[i]);
        string a, sign, b, equal, c;
        ss >> a >> sign >> b >> equal >> c;
        
        if (c == "X") xs.push_back(Exp(a, sign, b, c));
        else exps.push_back(Exp(a, sign, b, c));
    }
    
    // 모든 식에서 최대 자릿수 찾기
    int maxDigit = 0;
    for (Exp exp : exps) {
        maxDigit = max(maxDigit, exp.getMaxDigit());
    }
    for (Exp exp : xs) {
        maxDigit = max(maxDigit, exp.getMaxDigit());
    }
    
    // 최대 자릿수 + 1진법부터 시작
    vector<int> arys;
    for (int ary = maxDigit + 1; ary <= 9; ary++) {
        bool flag = true;
        for (Exp exp : exps) {
            if (!exp.isCollectAry(ary)) {
                flag = false;
                break;
            }    
        }
        if (flag) arys.push_back(ary);
    }
    
    vector<string> answer;
    for (Exp exp : xs) {
        vector<string> results;
        for (int ary : arys) {
            string result = exp.getResult(ary);
            if (!result.empty()) {
                results.push_back(result);
            }
        }
        
        bool allSame = true;
        if (results.size() > 1) {
            for (int i = 1; i < results.size(); i++) {
                if (results[i] != results[0]) {
                    allSame = false;
                    break;
                }
            }
        }
        
        if (allSame && !results.empty()) answer.push_back(exp.toString(results[0]));
        else answer.push_back(exp.toString("?"));
    }
    
    return answer;
}