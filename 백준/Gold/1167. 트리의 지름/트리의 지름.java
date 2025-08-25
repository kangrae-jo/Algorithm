import java.io.*;
import java.util.*;

public class Main {

    static int v;
    static List<List<int[]>> tree = new ArrayList<>();
    static int endNode, max = -1;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        v = Integer.parseInt(br.readLine());
        for (int i = 0; i <= v; i++) {
            tree.add(new ArrayList<>());
        }
        for (int i = 0; i < v; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cur = Integer.parseInt(st.nextToken());
            while (true) {
                int u = Integer.parseInt(st.nextToken());
                if (u == -1) break;
                int cost = Integer.parseInt(st.nextToken());
                tree.get(cur).add(new int[]{u, cost});
            }
        }
        br.close();

        visited = new boolean[v + 1];
        visited[1] = true;
        //max = -1;
        dfs(1, 0);

        visited = new boolean[v + 1];
        visited[endNode] = true;
        //max = -1;
        dfs(endNode, 0);

        System.out.println(max);
    }

    private static void dfs(int node, int len) {
        if (len > max) {
            max = len;
            endNode = node;
        }
        for (int[] next : tree.get(node)) {
            if (visited[next[0]]) continue;
            visited[next[0]] = true;
            dfs(next[0], len + next[1]);
        }
    }
}