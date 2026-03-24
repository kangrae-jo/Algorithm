#include <iostream>
#include <queue>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    priority_queue<int> pq;
    while(N--) {
        int x;
        cin >> x;
        
        if (x == 0) {
            if (pq.size() == 0) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
    
    
    return 0;
}
