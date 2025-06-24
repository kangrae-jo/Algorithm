#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end());

    int answer = 0;
    auto [prevS, prevE] = lines[0];

    for (auto [s, e] : lines) {
        if (prevE < s){
            answer += (prevE - prevS);
            prevS = s;
            prevE = e;
        }
        else prevE = max(prevE, e);
    }
    answer += (prevE - prevS);

    cout << answer;

    return 0;
}