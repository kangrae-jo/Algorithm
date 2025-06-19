import java.util.*;

class Solution {

    static class Word {
        char c;
        Map<Character, Word> nexts = new HashMap<>();
        int count = 0;

        Word(char c) {
            this.c = c;
        }
    }

    private void insert(Word cur, String word) {
        for (char ch : word.toCharArray()) {
            cur.nexts.putIfAbsent(ch, new Word(ch));
            cur = cur.nexts.get(ch);
            cur.count++;
        }
    }

    private int countType(Word cur, String word) {
        int cnt = 0;
        for (char ch : word.toCharArray()) {
            cnt++;
            cur = cur.nexts.get(ch);
            if (cur.count == 1) break;
        }
        return cnt;
    }

    public int solution(String[] words) {
        Word root = new Word(' ');
        for (String word : words) {
            insert(root, word);
        }

        int answer = 0;
        for (String word : words) {
            answer += countType(root, word);
        }

        return answer;
    }
}