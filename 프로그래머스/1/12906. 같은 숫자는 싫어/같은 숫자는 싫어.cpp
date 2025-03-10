#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int p = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (p != arr[i])  answer.push_back(arr[i]);
        p = arr[i];
    }

    return answer;
}