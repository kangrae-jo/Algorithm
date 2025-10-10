#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const string root = "minho";
const int price = 100;

vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
    int N = enroll.size();
    unordered_map<string, int> number;  // name -> number
    unordered_map<string, string> tree; // child name -> parent name
    
    for (int i = 0; i < N; i++) {
        string parent = referral[i];
        string child  = enroll[i];
        
        if (parent == "-") tree[child] = root;
        else tree[child] = parent;
        
        number[child] = i;
    }
    
    vector<int> answer(N, 0);
    for (int i = 0; i < seller.size(); i++) {
        string child = seller[i];
        int money = amount[i] * price;
        
        while(1) {
            int leave = money * 1 / 10;
            int remain = money - leave;
            
            string parent = tree[child];
            answer[number[child]] += remain;
            
            if (parent == root) break;
            if (leave == 0) break;
           
            child = parent;
            money = leave;
        }
    }
    
    return answer;
}
