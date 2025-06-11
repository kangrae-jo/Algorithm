#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int s = 0, e = N - 1;
    int s_ = s, e_ = e;

    long long sum = 2 * 1e9;
    long long sum_ = sum;

    while (s < e) {
        sum = nums[s] + nums[e];
        if (abs(sum_) >= abs(sum)) {
            sum_ = sum;
            s_ = s;
            e_ = e;
        }

        if (sum == 0) break;
        else if (sum > 0) e--;
        else s++;
    }

    cout << nums[s_] << " " << nums[e_] << endl;

    return 0;
}