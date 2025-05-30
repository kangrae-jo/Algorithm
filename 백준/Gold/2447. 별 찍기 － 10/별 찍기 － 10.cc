#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> stars;

void drawStars(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << stars[i][j];
        cout << '\n';
    }
}

void fillStars(int N, int x, int y) {
    if (N == 1) {
        stars[x][y] = '*';
        return;
    }
    
    int size = N / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            fillStars(size, x + i * size, y + j * size);
        }
    }
}

int main() {
    int N;
    cin >> N;

    stars.resize(N, vector<char>(N, ' '));
    fillStars(N, 0, 0);
    drawStars(N);

    return 0;
}