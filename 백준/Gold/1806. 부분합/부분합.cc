#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int answer = 100001;
    int s = 0, e = 0, sum = 0;

     while (true) {
        if (sum >= S) {
            answer = min(answer, e - s);
            sum -= nums[s++];
        } 
        else if (e == N) break;
        else sum += nums[e++];
    }

    if (answer == 100001) cout << 0 << endl;
    else cout << answer << endl;

    return 0;
}