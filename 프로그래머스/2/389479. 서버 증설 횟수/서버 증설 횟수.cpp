#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0; // 서버 증설 횟수
    vector<int> server (25, 1); // 현재 서버
    
    for (int time = 0; time < players.size(); time++) {
        int need = players[time] - (server[time] * m);
        if (need < 0) continue;
        else {
            int temp = need / m + 1;
            for (int i = 0; i < k && time + i < players.size(); i++) server[time + i] += temp;
            answer += temp;
        }
    }
    
    return answer;
}

/*
int need = players[time] - (server[time] * m);
        while (need >= 0) {
            for (int i=0; i<5 && time+i<players.size(); i++) server[time+i]++;
            answer++;
            
            need = players[time] - (server[time] * m) ;
        }
*/