import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

public class Main {

    static int[] arr;
    static int N;

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new int[N];
        int sum = 0;
        int maxBlueray = 0;
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            sum += arr[i];
            if (maxBlueray < arr[i])
                maxBlueray = arr[i];
        }
        System.out.println(binarySearch(maxBlueray, sum, M));


    }

    public static int binarySearch(int start, int end, int target) {
        while (start < end){
            int mid = (start + end) / 2;
            if (getCount(mid) > target)
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }

    private static int getCount(int mid) {
        int count = 1;
        int remain = mid;
        for (int i = 0; i < N; i++) {
            if (remain < arr[i]) {
                remain = mid;
                count++;
            }
            remain -= arr[i];
        }
        return count;
    }
}
