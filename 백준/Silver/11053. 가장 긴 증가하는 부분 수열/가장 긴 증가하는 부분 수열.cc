#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> num(N);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    vector<int> answer;
    for (int i = 0; i < N; i++) {
        if (answer.empty() || num[i] > answer.back()) answer.push_back(num[i]);
        else *lower_bound(answer.begin(), answer.end(), num[i]) = num[i];
    }

    cout << answer.size() << endl;

    return 0;
}