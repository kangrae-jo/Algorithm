#include <iostream>

using namespace std;

struct Pos {
    int x, y;

    Pos() {}
    Pos(int a, int b) : x(a), y(b) {}
};

int solution(Pos p1, Pos p2, Pos p3) {
    int s = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) -
            (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (s < 0) return -1;
    else if (s > 0) return 1;
    else return 0;
}

int main() {
    Pos p1, p2, p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    cout << solution(p1, p2, p3) << endl;

    return 0;
}