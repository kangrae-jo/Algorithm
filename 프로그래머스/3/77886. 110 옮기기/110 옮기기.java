class Solution {
    
    public String[] solution(String[] s) {
        String[] answer = new String[s.length];

        for (int i = 0; i < s.length; i++) {
            StringBuilder stack = new StringBuilder();
            int count110 = 0;

            for (char c : s[i].toCharArray()) {
                stack.append(c);
                int len = stack.length();

                if (len >= 3 &&
                    stack.charAt(len - 3) == '1' &&
                    stack.charAt(len - 2) == '1' &&
                    stack.charAt(len - 1) == '0') {

                    stack.delete(len - 3, len);
                    count110++;
                }
            }

            int pos = -1;
            for (int j = stack.length() - 1; j >= 0; j--) {
                if (stack.charAt(j) == '0') {
                    pos = j;
                    break;
                }
            }

            answer[i] = stack.insert(pos + 1, "110".repeat(count110)).toString();
        }

        return answer;
    }
    
}
