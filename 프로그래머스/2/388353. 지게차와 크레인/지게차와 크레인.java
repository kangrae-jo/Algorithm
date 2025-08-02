import java.util.*;

class Solution {

    static final int[][] OFFSET = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static int n, m;

    public int solution(String[] storage, String[] requests) {
        n = storage.length;
        m = storage[0].length();

        char[][] board = new char[n][m];
        for (int i = 0; i < n; i++) {
            board[i] = storage[i].toCharArray();
        }

        for (String request : requests) {
            char c = request.charAt(0);

            // 크레인
            if (request.length() == 2) {
                for (int y = 0; y < n; y++) {
                    for (int x = 0; x < m; x++) {
                        if (board[y][x] == c) {
                            board[y][x] = '0';
                        }
                    }
                }
            }
            // 지게차
            else {
                Queue<Pos> q = new LinkedList<>();
                for (int y = 0; y < n; y++) {
                    for (int x = 0; x < m; x++) {
                        if (board[y][x] == c && canRemove(board, y, x)) {
                            q.add(new Pos(y, x));
                        }
                    }
                }

                while (!q.isEmpty()) {
                    Pos p = q.poll();
                    board[p.y][p.x] = '0';
                }
            }
        }

        int answer = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board[y][x] != '0') answer++;
            }
        }

        return answer;
    }

    private static boolean canRemove(char[][] board, int y, int x) {
        boolean[][] visited = new boolean[n][m];
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(y, x));
        visited[y][x] = true;

        while (!q.isEmpty()) {
            Pos cur = q.poll();

            if (isOutLine(cur.y, cur.x)) return true;

            for (int dir = 0; dir < 4; dir++) {
                int nextY = cur.y + OFFSET[dir][0];
                int nextX = cur.x + OFFSET[dir][1];
                if (isIn(nextY, nextX) && !visited[nextY][nextX] && board[nextY][nextX] == '0') {
                    q.add(new Pos(nextY, nextX));
                    visited[nextY][nextX] = true;
                }
            }
        }

        return false;
    }

    private static boolean isOutLine(int y, int x) {
        return y == 0 || y == n - 1 || x == 0 || x == m - 1;
    }

    private static boolean isIn(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    private static class Pos {
        int y, x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}