import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    private static final int EMPTY = 0;
    private static final int WALL = 1;

    public static final int[][] OFFSET = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    public int solution(int[][] board) {
        int N = board.length;

        PriorityQueue<Pos> pq = new PriorityQueue<>(Comparator.comparingInt(pos -> pos.c));
        pq.add(new Pos(0, 0, 0, 0));
        pq.add(new Pos(0, 0, 0, 1));

        int[][][] dist = new int[4][N][N];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < N; j++) {
                Arrays.fill(dist[i][j], (int) 1e9);
            }
        }
        dist[0][0][0] = 0;
        dist[1][0][0] = 0;

        while (!pq.isEmpty()) {
            Pos cur = pq.poll();

            if (cur.y == N - 1 && cur.x == N - 1) {
                continue;
            }

            for (int dir = 0; dir < 4; dir++) {
                int y = cur.y + OFFSET[dir][0];
                int x = cur.x + OFFSET[dir][1];
                int c = cur.c + 100;
                if (dir != cur.d) {
                    c += 500;
                }

                if (isIn(y, x, N) && board[y][x] == EMPTY && dist[dir][y][x] > c) {
                    dist[dir][y][x] = c;
                    pq.add(new Pos(x, y, c, dir));
                }
            }
        }

        return Math.min(
                Math.min(dist[0][N - 1][N - 1], dist[1][N - 1][N - 1]),
                Math.min(dist[2][N - 1][N - 1], dist[3][N - 1][N - 1])
        );
    }

    private boolean isIn(int y, int x, int N) {
        return 0 <= y && y < N && 0 <= x && x < N;
    }

    private static class Pos {
        int x, y, c, d;

        public Pos(int x, int y, int c, int d) {
            this.x = x;
            this.y = y;
            this.c = c;
            this.d = d;
        }
    }
    
}
