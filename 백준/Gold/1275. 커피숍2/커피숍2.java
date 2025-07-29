import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static long[] nums;
    private static long[] tree;

    public static void main(String[] arg) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        nums = new long[N + 1];
        tree = new long[4 * (N + 1)];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        // 세그먼트 트리 만들기
        makeTree(1, N, 1);

        while (Q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            // 구간 합 찾기
            if (x <= y) {
                wr.write(Long.toString(solution(1, N, x, y, 1)));
            } else {
                wr.write(Long.toString(solution(1, N, y, x, 1)));
            }
            wr.newLine();

            // 일부 값 갱신
            updateTree(1, N, 1, a, b - nums[a]);
            nums[a] = b;
        }
        wr.flush();
    }

    private static void makeTree(int start, int end, int node) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        makeTree(start, mid, node * 2);
        makeTree(mid + 1, end, node * 2 + 1);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    private static long solution(int start, int end, int left, int right, int node) {
        if (right < start || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        return solution(start, mid, left, right, node * 2) +
                solution(mid + 1, end, left, right, node * 2 + 1);
    }

    private static void updateTree(int start, int end, int node, int index, long diff) {
        if (index < start || end < index) {
            return;
        }

        tree[node] += diff;
        if (start == end) {
            return;
        }

        int mid = (start + end) / 2;
        updateTree(start, mid, node * 2, index, diff);
        updateTree(mid + 1, end, node * 2 + 1, index, diff);
    }

}
