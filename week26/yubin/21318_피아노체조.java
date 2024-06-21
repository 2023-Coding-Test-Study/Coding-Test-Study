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
        int[] difficulty = new int[N+1];
        int[] arr = new int[N+1];
        int count = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            difficulty[i] = Integer.parseInt(st.nextToken());
            if(difficulty[i] < difficulty[i-1]) count++;
            arr[i] = count;
        }

        int Q = Integer.parseInt(br.readLine());
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            sb.append(arr[end] - arr[start]).append("\n");
        }


        System.out.println(sb.toString());

    }
}
