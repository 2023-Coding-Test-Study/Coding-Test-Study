import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());

        int[][] arr = new int[n + 1][n + 1];
        int[][][] dp = new int[n + 1][n + 1][3];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int now = arr[i][j];
                if (now == 0) {
                    dp[i][j][0] = Math.max(dp[i - 1][j][2], dp[i][j - 1][2]) + 1;
                } else {
                    dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i][j - 1][0]);
                }

                if (now == 1 && dp[i][j][0] > dp[i][j][1]) {
                    dp[i][j][1] = Math.max(dp[i - 1][j][0], dp[i][j - 1][0]) + 1;
                } else {
                    dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i][j - 1][1]);
                }

                if (now == 2 && dp[i][j][1] > dp[i][j][2]) {
                    dp[i][j][2] = Math.max(dp[i - 1][j][1], dp[i][j - 1][1]) + 1;
                } else {
                    dp[i][j][2] = Math.max(dp[i - 1][j][2], dp[i][j - 1][2]);
                }
            }
        }

        System.out.println(Math.max(dp[n][n][0], Math.max(dp[n][n][1], dp[n][n][2])));
    }
}
