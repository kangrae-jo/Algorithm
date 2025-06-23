#include <iostream>
#include <cmath>

using namespace std;

int main () {
    long long a, b;
    cin >> a >> b;
    
    if (a >= b) cout << abs(a - b);
    else cout << abs(b - a);
    
    return 0;
}