#include <iostream>

using namespace std;

struct Pos {
    long long x, y;
};

int ccw(Pos p1, Pos p2, Pos p3) {
    long long s = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
    if (s < 0) return -1;
    else if (s > 0) return 1;
    else return 0;
}

int isIntersect(Pos a, Pos b, Pos c, Pos d) {
    int abcd = ccw(a, b, c) * ccw(a, b, d);
    int cdab = ccw(c, d, a) * ccw(c, d, b);

    if (abcd < 0 && cdab < 0) return 1;
    else return 0;
}

int main() {
    // 1) input
    Pos a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    // 2) solution
    cout << isIntersect(a, b, c, d) << endl;

    return 0;
}