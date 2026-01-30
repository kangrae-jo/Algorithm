#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

extern string submit(int);

// 3024개 전체 경우 생성 (중복 없는 4자리)
void insertAllCase(vector<int>& list) {
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            if (a == b) continue;
            for (int c = 1; c <= 9; c++) {
                if (a == c || b == c) continue;
                for (int d = 1; d <= 9; d++) {
                    if (a == d || b == d || c == d) continue;
                    list.push_back(1000 * a + 100 * b + 10 * c + d);
                }
            }
        }
    }
}

// submit 결과에 따라 후보 리스트 필터링
vector<int> filterList(vector<int>& list, int num, int strike, int ball) {
    string strNum = to_string(num);

    unordered_set<char> numSet;
    for (int i = 0; i < 4; i++) {
        numSet.insert(strNum[i]);
    }

    vector<int> newList;
    for (int ele : list) {
        string number = to_string(ele);
        int strikeCnt = 0;
        int ballCnt = 0;

        for (int i = 0; i < 4; i++) {
            if (strNum[i] == number[i])       strikeCnt++;
            else if (numSet.count(number[i])) ballCnt++;
        }

        if (strikeCnt == strike && ballCnt == ball) {
            newList.push_back(ele);
        }
    }

    return newList;
}

int solution(int n) {
    vector<int> list;
    insertAllCase(list);

    // 후보가 1개 남을 때까지
    while (list.size() != 1) {
        int num = list[0];
        string result = submit(num);

        int strike = result[0] - '0';
        int ball   = result[3] - '0';
        list = filterList(list, num, strike, ball);
    }

    return list[0];
}