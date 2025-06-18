class Solution {
    public int solution(int[] a) {
        int N = a.length;
        if (N <= 3) return N;
        
        int[] lefts = new int[N];
        int[] rights = new int[N];
        
        lefts[0] = a[0];
        rights[N-1] = a[N-1];
        
        for (int i = 1; i < N; i++) {
            lefts[i] = Math.min(lefts[i - 1], a[i]);
        }
        for (int i = N - 2; i >= 0; i--) {
            rights[i] = Math.min(rights[i + 1], a[i]);
        }
        
        int answer = 2;
        for (int i = 1; i < N - 1; i++) {
            if (lefts[i] >= a[i] || rights[i] >= a[i]) answer++;
        }
        
        return answer;
    }
}