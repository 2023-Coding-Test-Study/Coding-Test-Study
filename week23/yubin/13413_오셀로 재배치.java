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

            String s1 = br.readLine();
            String s2 = br.readLine();

            int b = 0;
            int w = 0;
            int count = 0;

            for (int j = 0; j < N; j++) {
                if (s1.charAt(j) == s2.charAt(j)) {
                    continue;
                } else {
                    if (s1.charAt(j) == 'B') {
                        if (w > 0) {
                            w--;
                            count++;
                        } else {
                            b++;
                        }
                    } else {
                        if (b > 0) {
                            b--;
                            count++;
                        } else {
                            w++;
                        }
                    }
                }
            }

            count += b;
            count += w;

            sb.append(count).append("\n");
        }
        System.out.println(sb.toString());
    }
}
