#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int answer = 0;
    int left = 0, right = people.size() - 1;
    
    while (left <= right) {
        int sum = people[left] + people[right];
        if (sum <= limit) left++;
        right--;
        
        answer++;        
    }
    
    return answer;
}
