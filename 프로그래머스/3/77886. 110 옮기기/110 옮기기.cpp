#include <string>
#include <vector>

using namespace std;

bool is110(string stack, int len) {
    return stack[len - 3] == '1' && stack[len - 2] == '1' && stack[len - 1] == '0';
}

vector<string> solution(vector<string> s) {
    vector<string> answer(s.size());
    
    for (int i = 0; i < s.size(); i++) {
        string stack = "";
        int count110 = 0;
        
        for (char c : s[i]) {
            stack += c;
            int len = stack.size();
            
            if (len >= 3 && is110(stack, len)) {
                count110++;
                stack.erase(stack.end() - 3, stack.end());
            }
        }
        
        int pos = -1;
        for (int j = stack.size() - 1; j >= 0; j--) {
            if (stack[j] == '0') {
                pos = j;
                break;
            }
        }   
        
        string block = "";
        while (count110-- > 0) block += "110";
        
        answer[i] = stack.insert(pos + 1, block);        
    }
    
    return answer;
}
