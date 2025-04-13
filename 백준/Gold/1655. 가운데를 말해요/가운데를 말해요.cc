#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); 
    cin.tie(NULL);

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int N;
    cin >> N;

    while (N--) {
        int num;
        cin >> num;

        if (maxHeap.size() == minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);

        if(!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top())) {
			int max = maxHeap.top();
			int min = minHeap.top();
			
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(min);
			minHeap.push(max);
		}

        cout << maxHeap.top() << "\n";
    }

    return 0;
}