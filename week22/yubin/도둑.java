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

        int T = Integer.parseInt(st.nextToken());

        for (int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            int[] arr = new int[N];
            st = new StringTokenizer(br.readLine());
            int count = 0;
            for (int j = 0; j < N; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
                count += arr[j];
            }

            if (N == M) {
                if (count < K) {
                    // 훔칠 집 갯수와 현재 집 갯수가 동일하고 방범 알림이 울리지 않으므로 경우의수 1 출력
                    sb.append("1");
                } else {
                    // 훔칠 집 갯수와 현재 집 갯수가 동일하고 방범 알림이 울리므로 경우의수 0 출력
                    sb.append("0");
                }
            } else {
                // temp: 경우의수 갯수
                int temp = 0;

                int start = 0;
                int end = M - 1;
                int sum = 0;
                for (int j = 0; j <= end; j++) {
                    sum += arr[j];
                }

                while (start < N) {
                    // start가 N보다 작은 동안
                    if (sum < K) {
                        // 현재 돈의 합이 K보다 작으면
                        temp++;
                    }
                    sum -= arr[start];
                    start++;
                    end++;
                    // end가 N보다 클수있으므로 나머지연산
                    sum += arr[end % N];
                }
                sb.append(temp);
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }
}
