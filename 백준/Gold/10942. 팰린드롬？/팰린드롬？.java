import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static int[] nums;

    public static void main(String[] args) throws IOException {
        // 1) input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        nums = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());

        // 2) make dp table
        int[][] dp = new int[n + 1][n + 1];

        // 1
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 1;
        }

        // 2
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i + 1]) {
                dp[i][i + 1] = 1;
            } else {
                dp[i][i + 1] = 0;
            }
        }

        // 3 ...
        for (int s = n - 2; s > 0; s--) {
            for (int e = s + 2; e <= n; e++) {
                if (nums[s] == nums[e] && dp[s + 1][e - 1] == 1) {
                    dp[s][e] = 1;
                }
            }
        }

        // 3) answer
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < m; i++) {
            int s, e;
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());

            bw.write(String.valueOf(dp[s][e]));
            bw.newLine();
        }
        bw.flush();
    }
}
