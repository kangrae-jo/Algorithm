#include <iostream>
#include <vector>

using namespace std;

int N, M;

void print(vector<int> temp) {
    for (int t : temp) cout << t << " ";
    cout << '\n';
}

void back(vector<int> temp, int index) {
    if (temp.size() >= M) {
        print(temp);
        return;
    }

    for (int i = index + 1; i <= N; i++) {
        temp.push_back(i);
        back(temp, i);
        temp.pop_back();
    }
}

int main() {
    cin >> N >> M;

    vector<int> temp;
    back(temp, 0);

    return 0;
}