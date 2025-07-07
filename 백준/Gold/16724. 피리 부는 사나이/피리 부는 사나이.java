
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static char[][] board;

    public static void main(String[] arg) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        board = new char[n][m];
        for (int y = 0; y < n; y++) {
            String line = br.readLine();
            for (int x = 0; x < m; x++) {
                board[y][x] = line.charAt(x);
            }
        }

        /*
            there are three state.
            0 = Not visited
            1 = Ing
            2 = Complete
         */

        int[][] state = new int[n][m];
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                state[y][x] = 0;
            }
        }

        int answer = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (state[y][x] == 0) {
                    if (dfs(state, y, x)) {
                        answer++;
                    }
                }
            }
        }

        System.out.println(answer);
    }

    private static boolean dfs(int[][] state, int y, int x) {
        if (state[y][x] == 2) {
            return false;
        }
        if (state[y][x] == 1) {
            return true;
        }

        int y_ = 0, x_ = 0;
        if (board[y][x] == 'D') {
            y_++;
        }
        if (board[y][x] == 'U') {
            y_--;
        }
        if (board[y][x] == 'R') {
            x_++;
        }
        if (board[y][x] == 'L') {
            x_--;
        }

        state[y][x] = 1;
        boolean flag = dfs(state, y + y_, x + x_);
        state[y][x] = 2;
        return flag;
    }

}
