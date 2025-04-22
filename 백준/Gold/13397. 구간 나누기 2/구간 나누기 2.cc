#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;

bool canSplit(int limits) {
    int i = 0, m = 0;
    while (i < N) {
        int maxV = nums[i], minV = nums[i], diff = maxV - minV;
        while (i < N && diff <= limits) {
            i++;
            maxV = max(maxV, nums[i]);
            minV = min(minV, nums[i]);
            diff = maxV - minV;
        }
        m++;
    }
    if (m <= M) return true;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    nums.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int start = 0;
    int end = 10000;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (canSplit(mid)) end = mid - 1;
        else start = mid + 1;
    }

    cout << start << endl;

    return 0;
}