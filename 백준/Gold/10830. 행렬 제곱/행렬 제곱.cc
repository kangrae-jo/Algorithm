#include <iostream>
#include <vector>

using namespace std;

const int DIV = 1000;

long long N, B;
vector<vector<long long>> A, C;

vector<vector<long long>> mul(const vector<vector<long long>>& mat1, const vector<vector<long long>>& mat2) {
    vector<vector<long long>> result(N, vector<long long>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            for (int k = 0; k < N; k++) result[y][x] += (mat1[y][k] * mat2[k][x]) % DIV;
            result[y][x] %= DIV;
        }
    }
    return result;
}

int main() {
    cin >> N >> B;
    A = vector<vector<long long>>(N, vector<long long>(N));
    C = vector<vector<long long>>(N, vector<long long>(N, 0));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) cin >> A[y][x];
        C[y][y] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1) C = mul(C, A);
        A = mul(A, A);
        B /= 2;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) cout << C[y][x] << " ";
        cout << "\n";
    }

    return 0;
}