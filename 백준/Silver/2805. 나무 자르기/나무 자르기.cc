#include <iostream>
#include <vector>

using namespace std;

bool isEnough(vector<long long>& trees, int h, int m){
    long long sum = 0;
    for (long long tree : trees){
        if (tree - h > 0) sum += (tree - h);
    }

    if (sum >= m) return true;
    else return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> trees(N);
    for (int i = 0; i < N; i++){
        cin >> trees[i];
    }

    // binary search for H
    long long start = 0;
    long long end = 1000000000;
    long long mid;

    while (start <= end){
        mid = (start + end) / 2;
        
        if (isEnough(trees, mid, M)) start = mid + 1;
        else end = mid - 1;
    }

    cout << end;

    return 0;
}