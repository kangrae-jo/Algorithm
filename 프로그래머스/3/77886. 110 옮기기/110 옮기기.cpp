#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> numbers) {
    vector<string> answer;
    
    for (string number : numbers) {
        string stack = "";
        int count110 = 0;
        
        for (char c : number) {
            stack.push_back(c);
            int len = stack.size();
            
            if (len >= 3 &&
                stack[len-3] == '1' &&
                stack[len-2] == '1' &&
                stack[len-1] == '0') {
                stack.erase(stack.end() - 3, stack.end());
                count110++;
            }
        }
        
        int pos = -1;
        for (int i = stack.size() - 1; i >= 0; i--) {
            if (stack[i] == '0') {
                pos = i + 1;
                break;
            }
        }
        
        string block = "";
        while(count110-- > 0) block += "110";
        
        if (pos == -1) answer.push_back(block + stack);
        else answer.push_back(stack.insert(pos, block));
    }
    
    return answer;
}
