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

        int beforeAll = 0;
        int all = 3;
        int middle = 3;

        while (all < N) {
            beforeAll = all;
            all = all * 2 + (middle + 1);
            middle++;
        }

        System.out.println(moo(N, all, middle));
    }

    public static String moo(int N, int all, int middle) {
        int beforeAll = (all-middle)/2;
        if(N > beforeAll && N <= middle+beforeAll) {
            if(N == beforeAll+1) {
                return "m";
            } else {
                return "o";
            }
        } else if (N <= beforeAll) {
            return moo(N, beforeAll, middle-1);
        } else {
            return moo(N-beforeAll-middle, beforeAll, middle-1);
        }
    }
}
