#include <iostream>
#include <vector>

using namespace std;

vector<long long> nums;
vector<long long> tree;

long long makeTree(int start, int end, int node) {
    if (start == end) return tree[node] = nums[start];

    int mid = (start + end) / 2;

    return tree[node] = makeTree(start, mid, node * 2) + makeTree(mid + 1, end, node * 2 + 1);
}

long long solution(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return solution(start, mid, left, right, node * 2) +
           solution(mid + 1, end, left, right, node * 2 + 1);
}

void updateTree(int start, int end, int node, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] += diff;

    if (start == end) return;

    int mid = (start + end) / 2;
    updateTree(start, mid, node * 2, index, diff);
    updateTree(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    nums.assign(N + 1, 0);
    tree.assign(4 * (N + 1), 0);

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    makeTree(1, N, 1);

    while (Q--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);

        cout << solution(1, N, x, y, 1) << '\n';

        long long diff = b - nums[a];

        updateTree(1, N, 1, a, diff);
        nums[a] = b;
    }

    return 0;
}