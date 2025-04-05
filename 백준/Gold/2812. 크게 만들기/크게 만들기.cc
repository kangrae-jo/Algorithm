#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string num;

    cin >> N >> K;
    cin >> num;

    stack<int> s;
    for (int i = 0; i < N; i++) {
        int d = num[i] - '0';

        while (!s.empty() && d > s.top() && K > 0) {
            s.pop();
            K--;
        }
        s.push(d);
    }

    // 남아있는 K만큼 제거
    while (K > 0) {
        s.pop();
        K--;
    }

    // 스택을 뒤집어서 출력
    string result;
    while (!s.empty()) {
        result += (s.top() + '0');
        s.pop();
    }
    reverse(result.begin(), result.end());

    cout << result;

    return 0;
}