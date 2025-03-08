#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {   
    unordered_map<string, int> um;
    
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++){
        string temp = "";
        for (int s = 0; s < phone_book[i].size(); s++){
            temp += phone_book[i][s];
            if (um.find(temp) != um.end()) return false;
        }
        um[phone_book[i]]++;
    }
    return true;
}