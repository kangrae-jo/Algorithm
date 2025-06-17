class Solution {
    public int[] solution(int n, int s) {
        int[] answer = new int[n];
        if (n > s) return new int[] {-1};
        
        int num = s / n;
        for (int i = 0; i < n; i++) {
            answer[i] = num;
        }
        
        int over = s - num * n;
        int index = n - 1;
        
        while (over != 0) {
            answer[index--]++;
            over--;
        }
        
        return answer;
    }
}