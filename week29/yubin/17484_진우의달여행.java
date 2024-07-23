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

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] arr = new int[N][M];
        int[][][] dp = new int[N][M][3];
        // z0:왼쪽위에서 가져온 최솟값 // z1:위에서 가져온 최솟값 // z2:오른쪽위에서 가져온 최솟값 //

        // 입력값
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 맨윗줄 초기화
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 3; j++) {
                dp[0][i][j] = arr[0][i];
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {

                // 왼쪽위, 위, 오른쪽위 모두에서 비교 가능한 경우
                if (j > 0 && j < M - 1) {
                    dp[i][j][0] = arr[i][j] + Math.min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]); // z:0 = 왼쪽위에서 가져온 최솟값 & 같은방향 제외
                    dp[i][j][1] = arr[i][j] + Math.min(dp[i - 1][j][0], dp[i - 1][j][2]); // z:1 = 위에서 가져온 최솟값 & 같은방향 제외
                    dp[i][j][2] = arr[i][j] + Math.min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]); // z:2 = 오른쪽위에서 가져온 최솟값 & 같은방향 제외
                } else if (j == 0) {
                    dp[i][j][0] = Integer.MAX_VALUE;
                    dp[i][j][1] = arr[i][j] + Math.min(dp[i - 1][j][0], dp[i - 1][j][2]); // z:1 = 위에서 가져온 최솟값 & 같은방향 제외
                    dp[i][j][2] = arr[i][j] + Math.min(dp[i - 1][j + 1][0],
                            dp[i - 1][j + 1][1]); // z:2 = 오른쪽위에서 가져온 최솟값 & 같은방향 제외
                } else {
                    dp[i][j][0] = arr[i][j] + Math.min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]); // z:0 = 왼쪽위에서 가져온 최솟값 & 같은방향 제외
                    dp[i][j][1] = arr[i][j] + Math.min(dp[i - 1][j][0], dp[i - 1][j][2]); // z:1 = 위에서 가져온 최솟값 & 같은방향 제외
                    dp[i][j][2] = Integer.MAX_VALUE;
                }
            }
        }

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 3; j++) {
                min = Math.min(min, dp[N - 1][i][j]);
            }
        }

        System.out.println(min);

    }
}
