#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> dist(100002, -1);
vector<int> cnt(100002, 0);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << 0 << '\n' << 1;
        return 0;
    }

    dist[N] = 0;
    cnt[N] = 1;
    
    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (next < 0 || next > 100000) continue;
            if (dist[next] != -1) {
                if (dist[cur] + 1 == dist[next]) cnt[next] += cnt[cur];
            } else {
                dist[next] = dist[cur] + 1;
                cnt[next] = cnt[cur];      
                q.push(next);
            }
        }
    }

    cout << dist[K] << '\n' << cnt[K];

    return 0;
}