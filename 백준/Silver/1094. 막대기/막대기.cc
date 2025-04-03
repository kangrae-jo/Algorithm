#include <iostream>
#include <queue>

using namespace std;

int main () {
    int X;
    cin >> X;

    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(64);
    int sum = 64;

    while (sum > X) {
        int mini = pq.top();
        pq.pop();

        int out = mini / 2;
        pq.push(out);
        pq.push(out);
        
        if (sum - out >= X) {
            mini = pq.top();
            pq.pop();
            sum -= mini;
        }
    }
    
    cout << pq.size() << endl;

    return 0;
}