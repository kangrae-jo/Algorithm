#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long minSum = 3 * 1e9;
    int ans1, ans2, ans3;

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;
        while (left < right) {
            long long sum = nums[i] + nums[left] + nums[right];
            if (abs(sum) < abs(minSum)) {
                minSum = sum;
                ans1 = i;
                ans2 = left;
                ans3 = right;
            }
            if (sum < 0) left++;
            else right--;
        }
    }

    cout << nums[ans1] << " " << nums[ans2] << " " << nums[ans3] << '\n';

    return 0;
}