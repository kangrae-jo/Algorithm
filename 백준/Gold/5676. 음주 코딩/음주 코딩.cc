#include <iostream>
#include <vector>

using namespace std;

vector<int> X;
vector<int> tree;

int makeTree(int start, int end, int node) {
    if (start == end) return tree[node] = X[start];

    int mid = (start + end) / 2;
    return tree[node] = makeTree(start, mid, node * 2) *
                        makeTree(mid + 1, end, node * 2 + 1);
}

void updateTree(int start, int end, int node, int index, int V) {
    if (index < start || index > end) return;

    if (start == end) {
        tree[node] = V;
        return;
    }

    int mid = (start + end) / 2;
    updateTree(start, mid, node * 2, index, V);
    updateTree(mid + 1, end, node * 2 + 1, index, V);
    tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int solution(int start, int end, int left, int right, int node) {
    if (end < left || right < start) return 1;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return solution(start, mid, left, right, node * 2) *
           solution(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N, K;
    while (cin >> N >> K) {
        X.assign(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            int temp;
            cin >> temp;
            if (temp == 0) X[i] = 0;
            else if (temp > 0) X[i] = 1;
            else X[i] = -1;
        }

        tree.assign(4 * N + 4, 1);
        makeTree(1, N, 1);

        vector<char> answer;
        while (K--) {
            char command;
            cin >> command;

            if (command == 'C') {
                int i, V;
                cin >> i >> V;
                if (V > 0) V = 1;
                else if (V < 0) V = -1;
                updateTree(1, N, 1, i, V);
            } else if (command == 'P') {
                int i, j;
                cin >> i >> j;
                int temp = solution(1, N, i, j, 1);
                if (temp == 0) answer.push_back('0');
                else if (temp > 0) answer.push_back('+');
                else answer.push_back('-');
            }
        }

        for (char c : answer) cout << c;
        cout << '\n';
    }

    return 0;
}