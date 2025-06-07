#include <iostream>
using namespace std;

int N, r, c;

int solution(int x1, int y1, int x2, int y2, int count) {
    if (x2 - x1 == 1) {
        if (y1 == r && x1 == c) return count;
        if (y1 == r && x2 == c) return count + 1;
        if (y2 == r && x1 == c) return count + 2;
        if (y2 == r && x2 == c) return count + 3;
        return -1;
    }

    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    int len = (x2 - x1 + 1) / 2;
    int cntInBlock = len * len;

    if (r <= midY && c <= midX) // 1사분면
        return solution(x1, y1, midX, midY, count);
    else if (r <= midY && c > midX) // 2사분면
        return solution(midX + 1, y1, x2, midY, count + cntInBlock);
    else if (r > midY && c <= midX) // 3사분면
        return solution(x1, midY + 1, midX, y2, count + cntInBlock * 2);
    else // 4사분면
        return solution(midX + 1, midY + 1, x2, y2, count + cntInBlock * 3);
}

int main() {
    cin >> N >> r >> c;

    int size = 1 << N; // 2^N
    cout << solution(0, 0, size - 1, size - 1, 0);

    return 0;
}