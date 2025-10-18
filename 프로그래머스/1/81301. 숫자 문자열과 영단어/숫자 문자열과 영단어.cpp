#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, char> um = {
    {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, 
    {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}
};

int solution(string s) {
    string answer = "";
    string temp = "";

    for (char c : s) {
        if (isdigit(c)) answer += c;
        else {
            temp += c;
            if (um.find(temp) != um.end()) {
                answer += um[temp];
                temp = "";
            }
        }
    }

    return stoi(answer);
}