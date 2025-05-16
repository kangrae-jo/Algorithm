#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001] = {};

int main() {
    long long min, max;
    cin >> min >> max;

    long long s = 2, e = sqrt(max);
for (; s <= e; s++) {
    long long square = s * s;

    long long start = (min + square - 1) / square;
    long long temp = start * square;

    while (temp <= max) {
        visited[temp - min] = true;
        temp += square;
    }
}

    long long answer = max - min + 1;
    for (long long i = min; i <= max; i++) {
        if (visited[i - min]) answer--;
    }

    cout << answer << endl;

    return 0;
}