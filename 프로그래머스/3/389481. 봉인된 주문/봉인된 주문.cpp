#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long

using namespace std;

ll calculate(string s) {
    ll len = s.length();
    ll sum = 0;

    for (ll i = 0; i < len; i++) {
        char c = s[len - 1 - i];
        sum += (c - 'a' + 1) * pow(26, i);
    }
    
    return sum;
}

string makeStr(ll n) {
    vector<char> v;
    
    while (n > 0) {
        n--;
        v.push_back(n % 26 + 'a');
        n /= 26;
    }
    
    string result = "";
    for (ll i = v.size() - 1; i >= 0; i--) {
        result += string("") + v[i];
    }
    
    return result;
}

string solution(long long n, vector<string> bans) {
    vector<ll> nums;
    for (string ban : bans) {
        nums.push_back(calculate(ban));
    }
    
    sort(nums.begin(), nums.end());
    
    for (ll i = 0; i < nums.size(); i++) {
        if (nums[i] <= n) n++;
        else break;
    }
        
    return makeStr(n);
}