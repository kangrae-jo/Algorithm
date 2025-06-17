#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void fw(vector<vector<int>>& dist, int N) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int in, out;
        cin >> in >> out;
        dist[in][out] = 1;
        dist[out][in] = 1;
    }

    fw(dist, N);

    int answerV = 1e9, answerI = 0;
    for (int i = 1; i <= N; i++) {
        int temp = 0;
        for (int j = 1; j <= N; j++) {
            if (i != j) temp += dist[i][j];
        }

        if (answerV > temp) {
            answerV = temp;
            answerI = i;
        }
    }

    cout << answerI;

    return 0;
}