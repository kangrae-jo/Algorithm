#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const char TARGET = '8';

int main() {
    string L, R;
    cin >> L >> R;

    int answer = 0;
    if (L.length() != R.length()) answer = 0;
    else {
        for (int i = 0; i < L.length(); i++) {
            if (L[i] == TARGET && R[i] == TARGET) answer++;
            else if (L[i] != R[i]) break;
        }
    }

    cout << answer << endl;

    return 0;
}