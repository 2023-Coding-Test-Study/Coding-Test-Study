import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

public class Main {

    static List<Long> list;

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("src/input.txt"));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        list = new ArrayList<>();
        int n = Integer.parseInt(st.nextToken());

        if (n <= 10) {
            System.out.println(n);
        } else if(n > 1022) {
            System.out.println("-1");
        }else {
            for (int i = 0; i < 10; i++) {
                recursive(i, 1);
            }
            Collections.sort(list);
            System.out.println(list.get(n));
        }
    }

    static void recursive(long num, int index) {
        if(index > 10) return;

        list.add(num);
        for (int i = 0; i < num % 10; i++) {
            recursive((num * 10) + i, index + 1);
        }

    }

}
