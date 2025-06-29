#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    while (cin >> num && num != "0") {
        bool flag = true;
        for (int s = 0, e = num.size() - 1; s <= e; s++, e--) {
            if (num[s] != num[e]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}