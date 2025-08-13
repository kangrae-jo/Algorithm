#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

const string ANY = "-";

unordered_map<string, vector<int>> um;

string key(const string& a, const string& b, const string& c, const string& d) {
    return a + b + c + d;
}

vector<int> solution(vector<string> info, vector<string> query) {
    for (const string& str : info) {
        string lang, pos, year, food;
        int score;

        stringstream ss(str);
        ss >> lang >> pos >> year >> food >> score;

        um[key(lang, pos, year, food)].push_back(score);

        um[key(ANY,  pos, year, food)].push_back(score);
        um[key(lang, ANY, year, food)].push_back(score);
        um[key(lang, pos, ANY,  food)].push_back(score);
        um[key(lang, pos, year, ANY )].push_back(score);

        um[key(ANY,  ANY, year, food)].push_back(score);
        um[key(ANY,  pos, ANY,  food)].push_back(score);
        um[key(ANY,  pos, year, ANY )].push_back(score);
        um[key(lang, ANY, ANY,  food)].push_back(score);
        um[key(lang, ANY, year, ANY )].push_back(score);
        um[key(lang, pos, ANY,  ANY )].push_back(score);

        um[key(ANY,  ANY, ANY,  food)].push_back(score);
        um[key(ANY,  ANY, year, ANY )].push_back(score);
        um[key(ANY,  pos, ANY,  ANY )].push_back(score);
        um[key(lang, ANY, ANY,  ANY )].push_back(score);

        um[key(ANY,  ANY, ANY,  ANY )].push_back(score);
    }

    // socre 기준 정렬
    for (auto& entry : um) sort(entry.second.begin(), entry.second.end());

    vector<int> answer(query.size(), 0);
    for (int i = 0; i < query.size(); i++) {
        string lang, pos, year, food, ands;
        int score;

        stringstream ss(query[i]);
        ss >> lang >> ands >> pos >> ands >> year >> ands >> food >> score;

        auto it = um.find(key(lang, pos, year, food));
        if (it == um.end()) {
            answer[i] = 0; 
            continue;
        }

        // v는 정렬했으니 이분탐색
        vector<int> v = it->second;
        answer[i] = (v.end() - lower_bound(v.begin(), v.end(), score));
    }

    return answer;
}