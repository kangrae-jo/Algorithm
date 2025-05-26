#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(players.size(), 0);
    
    for (int time = 0; time < players.size(); time++) {
        int need = (players[time] - server[time] * m) / m;
        if (need <= 0) continue;
        
        answer += need;
        for (int i = 0; i < k && time + i < players.size(); i++) {
            server[time + i] += need;
        }
    }
    
    return answer;
}