
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> OFFSET= {-2, -1, 1, 2} ;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);

	for (test_case = 1; test_case <= T; ++test_case) {
		int N;
        cin >> N;
        
        vector<int> buildings(N);
        for (int i = 0; i < N; i++) {
         	cin >> buildings[i];  
        }
        
        int answer = 0;
      for (int i = 2; i < N - 2; i++) {
			int mid = buildings[i];
            
            int maxH = 0;
        	bool flag = true;
          
			for (int offset : OFFSET) {
                if (mid < buildings[i+offset]) {
                    flag = false;
                    break;
                }
                maxH = max(maxH, buildings[i+offset]);
            }
            
          if (flag) answer += (mid - maxH);
        }
       
		cout << "#" << test_case << " " << answer << '\n';
	}
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}