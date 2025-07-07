#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, bomb;
    cin >> str >> bomb;

    string answer = "";
    for (char c : str) {
        answer += c;

        if (answer.size() >= bomb.size()) {
            bool flag = true;
            for (int j = 0; j < bomb.size(); j++) {
                if (answer[answer.size() - bomb.size() + j] != bomb[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int j = 0; j < bomb.size(); j++) {
                    answer.pop_back();
                }
            }
        }
    }

    if (answer.empty()) cout << "FRULA";
    else cout << answer;

    return 0;
}