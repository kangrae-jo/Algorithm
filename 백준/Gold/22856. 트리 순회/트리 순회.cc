#include <iostream>
#include <unordered_map>

using namespace std;

const int LEAF = -1;

unordered_map<int, int> tree;  // root -> {right}

bool isEnd(int node) {
    return tree[node] == LEAF;
}

int solution(int node) {
    if (isEnd(node)) return 0;
    return solution(tree[node]) + 1;
}

int main() {
    // 1) input
    cin.tie(0)->sync_with_stdio(0);

    int N, all = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a] = c;
        all += 2;
    }

    // 2) solution
    int once = solution(1);
    cout << all - once - 2 << endl;

    return 0;
}