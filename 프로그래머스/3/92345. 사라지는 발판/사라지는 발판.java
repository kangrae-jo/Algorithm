class Solution {

    private static final int EMPTY = 0;
    private static final int PATH = 1;
    private static final int[][] OFFSET = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    private int N, M;

    public int solution(int[][] board, int[] aloc, int[] bloc) {
        N = board.length;
        M = board[0].length;

        return dfs(board, aloc[0], aloc[1], bloc[0], bloc[1]).count;
    }

    private Result dfs(int[][] board, int aY, int aX, int bY, int bX) {
        if (board[aY][aX] == EMPTY) {
            return new Result(false, 0);
        }

        boolean win = false;
        int minTurn = Integer.MAX_VALUE;
        int maxTurn = 0;

        for (int dir = 0; dir < 4; dir++) {
            int aY_ = aY + OFFSET[dir][0];
            int aX_ = aX + OFFSET[dir][1];
            if (isIn(aY_, aX_) && board[aY_][aX_] == PATH) {
                board[aY][aX] = EMPTY;
                Result next = dfs(board, bY, bX, aY_, aX_);
                board[aY][aX] = PATH; 

                if (!next.win) {
                    win = true;
                    minTurn = Math.min(minTurn, next.count + 1);
                } else if (!win) {
                    maxTurn = Math.max(maxTurn, next.count + 1);
                }
            }
        }

        if (win) return new Result(true, minTurn);
        else     return new Result(false, maxTurn);
    }

    private boolean isIn(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < M;
    }

    static class Result {
        boolean win;
        int count;

        Result(boolean win, int count) {
            this.win = win;
            this.count = count;
        }
    }
    
}
