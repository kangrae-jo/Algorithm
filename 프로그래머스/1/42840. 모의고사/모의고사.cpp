#include <algorithm>
#include <vector>

using namespace std;

vector<int> p0 = {1, 2, 3, 4, 5};
vector<int> p1 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> p2 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int getPoint(vector<int> answers, vector<int> p) {
    int point = 0;
    int len = p.size();
    
    for (int i = 0; i < answers.size(); i++) 
        if (answers[i] == p[i % len]) point++;
    
    return point;
}

vector<int> solution(vector<int> answers) {
    vector<vector<int>> pattern = {p0, p1, p2};
    vector<int> answer(3, 0);
    
    for (int i = 0; i < 3; i++)
        answer[i] = getPoint(answers, pattern[i]);
    
    int maxScore = max({answer[0], answer[1], answer[2]});
    
    vector<int> result;
    for (int i = 0; i < 3; i++) 
        if (answer[i] == maxScore) result.push_back(i + 1);

    return result;
}