#include <string>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<int> answer(2, 0);

bool canCompress(int sY, int sX, int eY, int eX){
    int temp = arr[sY][sX];
    for (int y = sY; y < eY; y++) for (int x = sX; x < eX; x++) 
        if (temp != arr[y][x]) return false;
    return true;
}

void compress(int startY, int endY, int startX, int endX) {
    if (canCompress(startY, startX, endY, endX)) {
        answer[arr[startY][startX]]++;
        return;
    }

    int midY = (startY + endY) / 2;
    int midX = (startX + endX) / 2;

    compress(startY, midY, startX, midX);
    compress(startY, midY, midX,   endX);
    compress(midY,   endY, startX, midX);
    compress(midY,   endY, midX,   endX);
}

vector<int> solution(vector<vector<int>> arr_) {
    arr = arr_;
    compress(0, arr.size(), 0, arr.size());
    return answer;
}