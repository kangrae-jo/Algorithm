#include <iostream>

using namespace std;

long long sol(long long  a, long long b) { return (a + b) * (a - b); }

int main() {
    long long a, b;
    cin >> a >> b;

    cout << sol(a, b);

    return 0;
}