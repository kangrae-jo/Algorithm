#include <iostream>

using namespace std;

int main() {
    int N, M, L;
    cin >> N >> M >> L;

    int input, total = 0;
    for (int i = 0; i < N; i++) {
        cin >> input;
        total += input;
    }

    int answer;
    if (total == M || total == 0) answer = 0;
    else if (M - total >= L) answer = 1;
    else if (total > M || total < L || L > M) answer = -1;
    else answer = 1;

    cout << answer << endl;

    return 0;
}