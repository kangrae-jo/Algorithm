#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> land(N);
    for (int i = 0; i < N; i++) {
        cin >> land[i];
    }

    vector<int> prefix(N + 1, 0);
    while (M--) {
        int a, b, k;
        cin >> a >> b >> k;

        prefix[a] += k;
        prefix[b + 1] -= k;
    }

    for (int i = 1; i <= N; i++) {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < N; i++) {
        cout << land[i] + prefix[i + 1] << " ";
    }

    return 0;
}