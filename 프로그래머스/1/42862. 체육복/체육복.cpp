#include <vector>
#include <algorithm>

using namespace std;

int student[31];

int solution(int n, vector<int> lost, vector<int> reserve) {   
    for(int i = 0; i < lost.size(); i++)    student[lost[i]]--;
    for(int i = 0; i < reserve.size(); i++) student[reserve[i]]++;
    
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(student[i] == -1){
            if(student[i - 1] == 1){
                student[i - 1] = 0;
                student[i] = 0;
            }
            else if(student[i + 1] == 1){
                student[i + 1] = 0;
                student[i] = 0;
            }
        }   
        if(student[i] >= 0) answer++;
    }
    
    return answer;
}