import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

public class Main {

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Map<Integer, Integer> map = new HashMap<>();
        int[] arr = new int[N];
        int front = 0;
        int end = 0;
        int sum = 0;
        int answer = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        map.put(arr[0], 1);

        while (true) {
            if (sum >= S) {
                sum -= arr[front];
                answer = Math.min(answer, end - front);
                front++;
            } else if (end == N) {
                break;
            } else {
                sum += arr[end++];
            }
        }

        if (answer == Integer.MAX_VALUE) {
            System.out.println("0");
        } else {
            System.out.println(answer);
        }
    }
}
