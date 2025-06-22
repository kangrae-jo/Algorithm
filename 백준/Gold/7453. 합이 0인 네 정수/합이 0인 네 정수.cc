#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<long long>> nums(N, vector<long long>(4));
    vector<long long> AB, CD;
    for (int i = 0; i < N; i++) {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB.push_back(nums[i][0] + nums[j][1]);
            CD.push_back(nums[i][2] + nums[j][3]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long answer = 0;
    for (int i = 0; i < AB.size(); i++) {
        long long preCD = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        long long endCD = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        if (CD[preCD] == -AB[i]) answer += (endCD - preCD);
    }

    cout << answer;

    return 0;
}