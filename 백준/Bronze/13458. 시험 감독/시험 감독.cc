#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> rooms(N);
    for (int i = 0; i < N; i++) {
        cin >> rooms[i];
    }

    int B, C;
    cin >> B >> C;

    long long answer = N;
    for (int room : rooms) {
        room -= B;
        if (room <= 0) continue;

        int temp = room / C;
        room %= C;

        answer += temp;
        if (room > 0) answer++;
    }

    cout << answer << endl;

    return 0;
}
