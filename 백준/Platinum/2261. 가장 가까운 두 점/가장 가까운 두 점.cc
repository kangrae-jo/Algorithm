#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

vector<pair<int, int>> points;

bool compareY(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int distance(const pair<int, int>& a, const pair<int, int>& b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int findMinPair(int p, int q) {
    // BASECASE
    if (p + 1 == q) return distance(points[p], points[q]);
    if (p + 2 == q) return min({distance(points[p], points[p + 1]), distance(points[p + 1], points[p + 2]), distance(points[p], points[q])});

    // Divide and Conquer
    int mid =( p + q) / 2;
    int minPair = min(findMinPair(p, mid), findMinPair(mid + 1, q));

    // select pairs
    vector<pair<int, int>> strip;
    strip.reserve(q - p + 1);
    int line = (points[mid].first + points[mid + 1].first) / 2;
    for (int i = p; i <= q; i++) {
        if (pow(line - points[i].first, 2) < minPair) {
            strip.push_back(points[i]);
        }
    }
    // sort by y
    sort(strip.begin(), strip.end(), compareY);

    // find minPair in strip
    int stripIndex = strip.size();
    for (int i = 0; i < stripIndex; i++)
        for (int j = i + 1; j < stripIndex; j++) {
            if (pow(strip[i].second - strip[j].second, 2) >= minPair) break;
            minPair = min(minPair, distance(strip[i], strip[j]));
        }

    return minPair;
}

int main() {
    // input
    int n;
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    // sort by x
    sort(points.begin(), points.end());

    // findMinPair
    cout << findMinPair(0, points.size()-1);

    return 0;
}
