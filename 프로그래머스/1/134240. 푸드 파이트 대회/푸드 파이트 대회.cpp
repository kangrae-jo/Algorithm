#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 1; i < food.size(); i++) {
        int t = food[i] / 2;
        while(t--) {
            answer += to_string(i);
        }
    }
    answer += "0";
    
    int len = answer.size();
    for (int i = 1; i < len; i++) {
        answer += answer[len - i - 1];
    }

    return answer;
}