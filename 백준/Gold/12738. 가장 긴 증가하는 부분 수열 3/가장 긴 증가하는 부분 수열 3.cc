#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;

int solution() {
    vector<int> answer;
    answer.push_back(A[0]);

    for (int i = 1; i < N; i++) {
        if (A[i] > answer.back()) answer.push_back(A[i]);
        else {
            auto iter = lower_bound(answer.begin(), answer.end(), A[i]);
            *iter = A[i];
        }
    }
    return answer.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solution() << endl;

    return 0;
}