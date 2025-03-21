#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dictionary;
vector<char> aeiou = {'A', 'E', 'I', 'O', 'U'};

void generate(string temp) {
    if (temp.size() > 5) return;
    if (!temp.empty()) dictionary.push_back(temp);

    for (char a : aeiou) generate(temp + a);
}

int solution(string word) {
    generate("");
    sort(dictionary.begin(), dictionary.end());

    return find(dictionary.begin(), dictionary.end(), word) - dictionary.begin() + 1;
}