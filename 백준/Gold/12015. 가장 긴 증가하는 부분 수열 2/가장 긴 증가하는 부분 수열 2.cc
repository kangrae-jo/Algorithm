#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> num(N);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    vector<int> arr;
    arr.push_back(num[0]);

    for (int i = 1; i < N; i++) {
        if (num[i] > arr.back())  arr.push_back(num[i]);
        else {
            auto pos = lower_bound(arr.begin(), arr.end(), num[i]);
            *pos = num[i];
        }
    }

    cout << arr.size() << endl; 

    return 0;
}