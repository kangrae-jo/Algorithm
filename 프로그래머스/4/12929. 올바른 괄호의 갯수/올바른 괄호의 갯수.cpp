#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    vector<char> str;
    for (int i = 0; i < n; i++) {
        str.push_back('(');
        str.push_back(')');
    }
    
    int answer = 0;
    sort(str.begin(), str.end());
    do {
        int temp = 0;
        for (int i = 0; i < n * 2; i++) {
            if (str[i] == '(') temp++;
            else temp--;
            if (temp > 0) break;
        }
        if (temp == 0) answer++;
        
    } while (next_permutation(str.begin(), str.end()));
    
    return answer;
}