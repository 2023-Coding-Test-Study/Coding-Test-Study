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
        int K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Map<Integer, Integer> map = new HashMap<>();
        int[] arr = new int[N];
        int front = 0;
        int end = 1;

        int answer = 0;

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        map.put(arr[0], 1);
        while (end < N) {
            while (end < N && map.getOrDefault(arr[end], 0) + 1 <= K) {
                map.put(arr[end], map.getOrDefault(arr[end], 0) + 1);
                end++;
            }

            answer = Math.max(answer, end - front);

            map.put(arr[front], map.getOrDefault(arr[front], 1) - 1);
            front++;
        }

        System.out.println(answer);
    }
}
